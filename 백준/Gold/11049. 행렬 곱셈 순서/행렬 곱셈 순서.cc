// no.11049: 행렬 곱셈 순서 (G3)

#include <iostream>
#include <vector>
#include <functional>
#define MIN(a, b) ((a < b) ? a : b)
using namespace std;

int dp[501][501];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n+1, make_pair(0, 0));
    for(int i=1; i<=n; i++) {
        int r, c;
        cin >> r >> c;
        arr[i] = make_pair(r, c);
    }
    // init
    for(int i=0; i<=n; i++) {
        dp[i][i] = 0;
    }
    for(int i=1; i<=n-1; i++) {
        dp[i][i+1] = arr[i].first * arr[i].second * arr[i+1].second;
    }
    // dp
    for(int i=2; i<n; i++) {
        for(int j=1; j<=n-i; j++) {
            dp[j][j+i] = dp[j+1][j+i] + arr[j].first * arr[j].second * arr[j+i].second;
            for(int k=j+1; k<j+i; k++) {
                int cost = arr[j].first * arr[k].second * arr[j+i].second;
                dp[j][j+i] = MIN(dp[j][k] + dp[k+1][j+i] + cost, dp[j][j+i]);
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}