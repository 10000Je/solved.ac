// no.1005: ACM Craft (G3)

#include <cstdio>
#include <vector>
#include <queue>
#define MAX(a, b) ((a > b) ? a : b)
using namespace std;

void topologySort(const vector<int>& cost, const vector<vector<int>>& graph, vector<int>& inorder, vector<int>& dp);

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> cost(n+1, 0);
        vector<int> inorder(n+1, 0);
        vector<vector<int>> graph(n+1, vector<int>());
        vector<int> dp(n+1, 0);
        for(int j=1; j<=n; j++) {
            scanf("%d", &cost[j]);
        }
        for(int j=0; j<k; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            inorder[y]++;
        }
        topologySort(cost, graph, inorder, dp);
        int w;
        scanf("%d", &w);
        printf("%d\n", dp[w]);
    }
    return 0;
}

void topologySort(const vector<int>& cost, const vector<vector<int>>& graph, vector<int>& inorder, vector<int>& dp) {
    queue<int> que;
    int n = cost.size() - 1;
    for(int i=1; i<=n; i++) {
        if(inorder[i] == 0) {
            que.push(i);
            dp[i] = cost[i];
        }
    }
    while(!que.empty()) {
        int x = que.front();
        que.pop();
        for(int node : graph[x]) {
            dp[node] = MAX(dp[node], dp[x]+cost[node]);
            inorder[node]--;
            if(inorder[node] == 0) {
                que.push(node);
            }
        }
    }
}