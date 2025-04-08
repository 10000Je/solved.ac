// no.1667: 트리의 지름 (G2)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF int(1e9)
using namespace std;

int v;
vector<vector<pair<int, int>>> tree;
void bfs(int loc, vector<int>& dist);

int main() {   
    scanf("%d", &v);
    tree.assign(v+1, vector<pair<int, int>>());
    for(int i=0; i<v; i++) {
        int n;
        scanf("%d", &n);
        while(true) {
            int a, b;
            scanf("%d", &a);
            if(a == -1) {
                break;
            }
            scanf("%d", &b);
            tree[n].push_back(make_pair(a, b));
        }
    }
    vector<int> dist;
    bfs(1, dist);
    int loc = distance(dist.begin(), max_element(dist.begin(), dist.end()));
    bfs(loc, dist);
    int d = *max_element(dist.begin(), dist.end());
    printf("%d\n", d);
    return 0;
}

void bfs(int loc, vector<int>& dist) {
    dist.clear(); dist.assign(v+1, -1);
    queue<int> que; que.push(loc);
    vector<bool> visit(v+1, false);
    dist[loc] = 0;
    while(!que.empty()) {
        int x = que.front();
        que.pop();
        for(pair<int, int> edge : tree[x]) {
            int node = edge.first, cost = edge.second;
            if(dist[node] != -1) {
                continue;
            }
            dist[node] = dist[x] + cost;
            que.push(node);
        }
    }
}