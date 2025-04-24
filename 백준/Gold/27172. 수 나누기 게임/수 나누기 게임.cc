// no.27172: 수 나누기 게임 (G4)

#include <cstdio>
#include <vector>
using namespace std;

int score[1'000'001];
bool exist[1'000'001];

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
        exist[nums[i]] = true;
    }
    for(int num : nums) {
        int tmp = num*2;
        while(tmp <= 1'000'000) {
            if(exist[tmp]) {
                score[tmp]--;
                score[num]++;
            }
            tmp += num;
        }
    }
    for(int num : nums) {
        printf("%d ", score[num]);
    }
    printf("\n");
    return 0;
}