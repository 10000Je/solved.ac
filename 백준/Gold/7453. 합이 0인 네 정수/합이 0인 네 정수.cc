// no.7453: 합이 0인 네 정수 (G2)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int64;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n), D(n);
    for(int i=0; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        D[i] = d;
    }
    vector<int> AB, CD;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    int left = 0;
    int right = n*n-1;
    int64 count = 0;
    while(left < n*n && right >= 0) {
        if(AB[left] + CD[right] > 0) {
            right--;
        }
        else if(AB[left] + CD[right] < 0) {
            left++;
        }
        // if a + b + c + d is 0
        else {
            int temp = AB[left];
            int64 c1 = 0;
            while(left < n*n && AB[left] == temp) {
                left++;
                c1++;
            }
            temp = CD[right];
            int64 c2 = 0;
            while(right >= 0 && CD[right] == temp) {
                right--;
                c2++;
            }
            count += c1*c2;
        }
    }
    cout << count << '\n';
    return 0;
}