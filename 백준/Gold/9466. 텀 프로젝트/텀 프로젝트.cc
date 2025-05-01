// no.9466: 텀 프로젝트

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topology_sort(const vector<vector<int>>& graph, vector<int>& inorder);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> inorder(n+1, 0);
        vector<vector<int>> graph(n+1, vector<int>());
        for(int i=1; i<=n; i++) {
            int j;
            cin >> j;
            graph[i].push_back(j);
            inorder[j]++;
        }
        topology_sort(graph, inorder);
        int count = 0;
        for(int i=1; i<=n; i++) {
            if(inorder[i] == 0) {
                count++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}

void topology_sort(const vector<vector<int>>& graph, vector<int>& inorder) {
    int n = inorder.size() - 1;
    queue<int> que;
    for(int i=1; i<=n; i++) {
        if(inorder[i] == 0)
            que.push(i);
    }
    while(!que.empty()) {
        int x = que.front(); que.pop();
        for(int node : graph[x]) {
            inorder[node]--;
            if(inorder[node] == 0)
                que.push(node);
        }
    }
}