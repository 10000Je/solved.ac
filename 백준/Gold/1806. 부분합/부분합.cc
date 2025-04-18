// no.1806: 부분합 (G4)

#include <cstdio>
#include <vector>
#define MIN(a, b) (a < b) ? a : b
using namespace std;

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int left = 0, right = 0;
    int sum = arr[0];
    int min = n+1;
    while(true) {
        if(sum >= s) {
            int cur = right - left + 1;
            min = MIN(min, cur);
            sum -= arr[left];
            left++;
            if(left > right) {
                break;
            }
        }
        else {
            right++;
            if(right >= n) {
                break;
            }
            sum += arr[right];
        }
    }
    if(min == n+1) {
        printf("0\n");
    }
    else {
        printf("%d\n", min);
    }
    return 0;
}