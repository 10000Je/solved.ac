// no.15681: 트리와 쿼리 (G5)

#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> dp;

int dfs(int root, vector<bool>& visit);

int main() {
    int n, r, q;
    scanf("%d %d %d", &n, &r, &q);
    dp.assign(n+1, 0);
    graph.assign(n+1, vector<int>());
    for(int i=0; i<n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visit(n+1, false);
    dp[r] = dfs(r, visit);
    for(int i=0; i<q; i++) {
        int u;
        scanf("%d", &u);
        printf("%d\n", dp[u]);
    }
    return 0;
}

int dfs(int root, vector<bool>& visit) {
    visit[root] = true;
    int ret = 1;
    for(int node : graph[root]) {
        if(visit[node]) {
            continue;
        }
        if(dp[node] == 0) {
            dp[node] = dfs(node, visit);
        }
        ret += dp[node];
    }
    return ret;
}