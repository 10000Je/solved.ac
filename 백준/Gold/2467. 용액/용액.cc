// no.2467: 용액 (G5)

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> sols;
    for(int i=0; i<n; i++) {
        int val;
        scanf("%d", &val);
        sols.push_back(val);
    }
    int left = 0;
    int right = n-1;
    int val = sols[left] + sols[right];
    pair<int, int> min = make_pair(left, right);
    while(left < right) {
        if(abs(sols[left]+sols[right]) < abs(sols[min.first]+sols[min.second])) {
            min = make_pair(left, right);
        }
        if(sols[left]+sols[right] < 0) {
            left++;
        }
        else {
            right--;
        }  
    }
    printf("%d %d\n", sols[min.first], sols[min.second]);
    return 0;
}