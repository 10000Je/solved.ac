// no.2143: 두 배열의 합 (G3)

#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef long long int64;

void calc(const vector<int>& arr, map<int, int64>& sum);

int main() {
    int t, n;
    scanf("%d %d", &t, &n);
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    int m;
    scanf("%d", &m);
    vector<int> b(m+1);
    for(int i=1; i<=m; i++) {
        scanf("%d", &b[i]);
    }

    map<int, int64> sum_a, sum_b;
    calc(a, sum_a);
    calc(b, sum_b);

    int64 count = 0;
    for(pair<int, int> entry : sum_a) {
        int key = entry.first;
        int64 value = entry.second;
        if(sum_b.count(t-key) != 0) {
            count += (value * sum_b[t-key]);
        }
    }
    printf("%lld\n", count);
    return 0;
}

void calc(const vector<int>& arr, map<int, int64>& sum) {
    int n = arr.size()-1;
    vector<int> dp(n+1);
    for(int i=1; i<=n; i++) {
        dp[i] = dp[i-1] + arr[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            int k = dp[j] - dp[i-1];
            if(sum.count(k) == 0) {
                sum[k] = 1;
            }
            else {
                sum[k] += 1;
            }
        }
    }
}