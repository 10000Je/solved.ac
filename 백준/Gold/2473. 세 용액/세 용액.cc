// no.2473: 세 용액 (G3)

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
typedef long long int64;
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    vector<int64> arr(n, 0);
    for(int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    tuple<int, int, int> result = make_tuple(0, 1, 2);
    for(int i=0; i<n; i++) {
        int left = 0, right = n-1;
        if(i == 0) {
            left++;
        }
        if(i == n-1) {
            right--;
        }
        while(left < right) {
            int64 sum = arr[i] + arr[left] + arr[right];
            if(abs(sum) < abs(arr[get<0>(result)] + arr[get<1>(result)] + arr[get<2>(result)])) {
                result = make_tuple(i, left, right);
            }
            if(sum < 0) {
                left++;
                if(left == i) {
                    left++;
                }
            }
            else {
                right--;
                if(right == i) {
                    right--;
                }
            }
        }
    }
    vector<int64> nums = {arr[get<0>(result)], arr[get<1>(result)], arr[get<2>(result)]};
    sort(nums.begin(), nums.end());
    for(int64 num : nums) {
        printf("%lld ", num);
    }
    printf("\n");
    return 0;
}