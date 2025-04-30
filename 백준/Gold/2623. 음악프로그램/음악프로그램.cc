// no.2623: 음악프로그램 (G3)

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int inorder[1001];
vector<vector<int>> graph;
int n;

bool topology_sort(vector<int>& result);

int main() {
    int m;
    scanf("%d %d", &n, &m);
    graph.assign(n+1, vector<int>());
    for(int i=0; i<m; i++) {
        int k;
        scanf("%d", &k);
        vector<int> order(k, 0);
        for(int j=0; j<k; j++) {
            scanf("%d", &order[j]);
        }
        for(int j=0; j<k-1; j++) {
            graph[order[j]].push_back(order[j+1]);
            inorder[order[j+1]]++;
        }
    }
    vector<int> result;
    bool is_valid = topology_sort(result);
    if(is_valid) {
        for(int num : result) {
            printf("%d\n", num);
        }
    }
    else {
        printf("0\n");
    }
    return 0;
}

bool topology_sort(vector<int>& result) {
    queue<int> que;
    for(int i=1; i<=n; i++) {
        if(inorder[i] == 0) {
            que.push(i);
        }
    }
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
    for(int i=1; i<=n; i++) {
        if(inorder[i] != 0) {
            return false;
        }
    }
    return true;
}