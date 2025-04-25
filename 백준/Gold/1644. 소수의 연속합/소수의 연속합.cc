// no.1644: 소수의 연속합 (G3)

#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if(n == 1) {
        printf("0\n");
        return 0;
    }
    vector<bool> arr(n+1, true);
    // 에라토스테네스의 체
    for(int i=2; i*i<=n; i++) {
        if(!arr[i]) {
            continue;
        }
        int tmp = i*2;
        while(tmp <= n) {
            arr[tmp] = false;
            tmp += i;
        }
    }
    vector<int> primes;
    for(int i=2; i<=n; i++) {
        if(arr[i]) {
            primes.push_back(i);
        }
    }
    // 투 포인터
    int left = 0, right = 0;
    int sum = primes[0];
    int count = 0;
    while(left <= right) {
        if(sum <= n) {
            if(sum == n) {
                count++;
            }
            right++;
            if(right >= primes.size()) {
                break;
            }
            sum += primes[right];
        }
        else {
            sum -= primes[left];
            left++;
        }
    }
    printf("%d\n", count);
    return 0;
}