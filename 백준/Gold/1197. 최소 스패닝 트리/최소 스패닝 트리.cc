// no.1197: 최소 스패닝 트리 (G4)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int find(int x);
void _union(int a, int b);

vector<int> parent;

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    parent.assign(v+1, 0);
    for(int i=1; i<=v; i++) {
        parent[i] = i;
    }
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<e; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back(make_tuple(c, a, b));
    }
    sort(edges.begin(), edges.end());
    int ret = 0;
    for(tuple<int, int, int> edge : edges) {
        int c = get<0>(edge), a = get<1>(edge), b = get<2>(edge);
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b) {
            ret += c;
            _union(a, b);
        }
    }
    printf("%d\n", ret);
    return 0;
}

int find(int x) {
    if(x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void _union(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    parent[root_a] = root_b;
}