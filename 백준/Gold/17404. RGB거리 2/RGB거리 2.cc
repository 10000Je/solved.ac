// no.17404: RGB거리 2 (G4)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#define INF 1'000'000
using namespace std;

void paint(vector<vector<int>>& dp);
vector<vector<int>> cost;
int n;

int main() {
    scanf("%d", &n);
    cost.assign(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    vector<vector<int>> dp(n, vector<int>(3, INF));
    dp[0][0] = cost[0][0]; dp[0][1] = INF; dp[0][2] = INF;
    paint(dp);
    int r = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    dp[0][1] = cost[0][1]; dp[0][0] = INF; dp[0][2] = INF;
    paint(dp);
    int g = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    dp[0][2] = cost[0][2]; dp[0][0] = INF; dp[0][1] = INF;
    paint(dp);
    int b = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    printf("%d\n", min({r, g, b}));
    return 0;
}

void paint(vector<vector<int>>& dp) {
    for(int i=1; i<n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }
    if(dp[0][0] != INF) {
        dp[n-1][0] = INF;
    }
    if(dp[0][1] != INF) {
        dp[n-1][1] = INF;
    }
    if(dp[0][2] != INF) {
        dp[n-1][2] = INF;
    }
}