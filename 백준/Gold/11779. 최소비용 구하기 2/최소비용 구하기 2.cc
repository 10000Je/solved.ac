// no.11779: 최소비용 구하기 2 (G3)

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define INF int(1e8)
using namespace std;

vector<vector<pair<int, int>>> graph;
int n, s, e;

void dijkstra(vector<int>& route, vector<int>& dist);
vector<int> get_path(vector<int>& route);

int main() {
    int m;
    scanf("%d %d", &n, &m);
    graph.assign(n+1, vector<pair<int, int>>());
    for(int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
    }
    scanf("%d %d", &s, &e);
    vector<int> route, dist;
    dijkstra(route, dist);
    printf("%d\n", dist[e]);
    vector<int> path = get_path(route);
    printf("%zu\n", path.size());
    for(int node : path) {
        printf("%d ", node);
    }
    printf("\n");
    return 0;
}

void dijkstra(vector<int>& route, vector<int>& dist) {
    route.clear(); dist.clear();
    vector<bool> visit(n+1, false);
    route.assign(n+1, 0);
    dist.assign(n+1, INF);
    dist[s] = 0;
    route[s] = s;
    priority_queue<pair<int, int>> queue;
    queue.push(make_pair(-dist[s], s));
    while(!queue.empty()) {
        int x = queue.top().second;
        queue.pop();
        if(visit[x]) {
            continue;
        }
        visit[x] = true;
        for(pair<int, int> edge : graph[x]) {
            int node = edge.first, cost = edge.second;
            if(visit[node]) {
                continue;
            }
            if(dist[x]+cost < dist[node]) {
                dist[node] = dist[x]+cost;
                route[node] = x;
                queue.push(make_pair(-dist[node], node));
            }
        }
    }
}

vector<int> get_path(vector<int>& route) {
    vector<int> ret;
    int x = e;
    ret.push_back(e);
    while(x != route[x]) {
        x = route[x];
        ret.push_back(x);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}