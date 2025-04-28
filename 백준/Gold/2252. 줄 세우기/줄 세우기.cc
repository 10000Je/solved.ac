// no.2252: 줄 세우기 (G3)

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int> inorder;
vector<vector<int>> graph;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    inorder.assign(n+1, 0);
    graph.assign(n+1, vector<int>());
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        inorder[b]++;
    }
    queue<int> que;
    for(int i=1; i<=n; i++) {
        if(inorder[i] == 0) {
            que.push(i);
        }
    }
    vector<int> result;
    while(!que.empty()) {
        int x = que.front();
        result.push_back(x);
        que.pop();
        for(int node : graph[x]) {
            inorder[node]--;
            if(inorder[node] == 0) {
                que.push(node);
            }
        }
    }
    for(int num : result) {
        printf("%d ", num);
    }
    printf("\n");
    return 0;
}