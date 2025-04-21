// no.9252: LCS 2 (G4)

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX(a, b) ((a > b) ? a : b)
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = MAX(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = n, j = m;
    string ret;
    while(i != 0 && j != 0) {
        if(s1[i-1] == s2[j-1]) {
            ret.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] >= dp[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    reverse(ret.begin(), ret.end());
    cout << dp[n][m] << endl;
    cout << ret << endl;
    return 0;
}