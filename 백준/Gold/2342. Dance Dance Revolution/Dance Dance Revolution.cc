// no.2342: Dance Dance Revolution (G3)

#include <cstdio>
#include <vector>
#include <cmath>
#define INF int(1e6)
#define MIN(a, b) ((a < b) ? a : b)
using namespace std;

int dp[100'001][5][5];

int main() {
    int num;
    scanf("%d", &num);
    vector<int> inst;
    inst.push_back(0);
    while(num != 0) {
        inst.push_back(num);
        scanf("%d", &num);
    }
    int n = inst.size()-1;
    // initialize
    for(int i=0; i<=n; i++) {
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    // dynamic programming
    dp[0][0][0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                if(dp[i][j][k] != INF) {
                    int target = inst[i+1];
                    // left foot move
                    if(target != k) {
                        if(j == 0) {
                            dp[i+1][target][k] = MIN(dp[i+1][target][k], dp[i][j][k] + 2);
                        }
                        else if(abs(j-target) == 2){
                            dp[i+1][target][k] = MIN(dp[i+1][target][k], dp[i][j][k] + 4);
                        }
                        else if(abs(j-target) == 0) {
                            dp[i+1][target][k] = MIN(dp[i+1][target][k], dp[i][j][k] + 1);
                        }
                        else {
                            dp[i+1][target][k] = MIN(dp[i+1][target][k], dp[i][j][k] + 3);
                        } 
                    }                   
                    // right foot move
                    if(target != j) {
                        if(k == 0) {
                            dp[i+1][j][target] = MIN(dp[i+1][j][target], dp[i][j][k] + 2);
                        }
                        else if(abs(k-target) == 2) {
                            dp[i+1][j][target] = MIN(dp[i+1][j][target], dp[i][j][k] + 4);
                        }
                        else if(abs(k-target) == 0) {
                            dp[i+1][j][target] = MIN(dp[i+1][j][target], dp[i][j][k] + 1);
                        }
                        else {
                            dp[i+1][j][target] = MIN(dp[i+1][j][target], dp[i][j][k] + 3);
                        }
                    }    
                }
            }
        }
    }
    int min = INF;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            min = MIN(dp[n][i][j], min);
        }
    }
    printf("%d\n", min);
    return 0;
}