// no.7579: 앱 (G3)

#include <cstdio>
#include <vector>
#define MAX(a, b) ((a > b) ? a : b)
using namespace std;

int dp[101][10001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n+1, 0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    vector<int> c(n+1, 0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &c[i]);
    }
    for(int j=0; j<=10000; j++) {
        for(int i=1; i<=n; i++) {
            if(c[i] <= j) {
                dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-c[i]] + v[i]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
            if(dp[i][j] >= m) {
                printf("%d\n", j);
                return 0;
            }
        }
    }
    return 0;
}