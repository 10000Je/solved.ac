// no.10942: 팰린드롬? (G4)

#include <cstdio>
#include <vector>
using namespace std;

bool dp[2001][2001];

int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n+1, 0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=1; i<=n; i++) {
        dp[i][i] = true;
    }
    for(int i=1; i<=n-1; i++) {
        if(arr[i] == arr[i+1]) {
            dp[i][i+1] = true;
        }
    }
    for(int i=2; i<n; i++) {
        for(int j=1; j<=n-i; j++) {
            if(arr[j] == arr[j+i]) {
                dp[j][j+i] = dp[j+1][j+i-1];
            }
        }
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e] ? 1 : 0);
    }
    return 0;
}