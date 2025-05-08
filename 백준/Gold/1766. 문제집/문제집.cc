// no.1766: 문제집 (G2)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int inorder[32001] = {0};
vector<vector<int>> graph;
int n, m;

void topology_sort(vector<int>& result);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    graph.assign(n+1, vector<int>());
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inorder[b]++;
    }
    vector<int> result;
    topology_sort(result);
    for(int num : result) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}

void topology_sort(vector<int>& result) {
    result.clear();
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i=1; i<=n; i++) {
        if(inorder[i] == 0)
            heap.push(i);
    }
    while(!heap.empty()) {
        int x = heap.top();
        heap.pop();
        result.push_back(x);
        for(int node : graph[x]) {
            inorder[node]--;
            if(inorder[node] == 0)
                heap.push(node);
        }
    }
}
