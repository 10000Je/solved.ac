// no.1647: 도시 분할 계획 (G4)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int find(int x);
void _union(int a, int b);
bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b);

int parent[100'001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back(make_tuple(a, b, c));
    }
    sort(edges.begin(), edges.end(), compare);
    int total = 0;
    int last = 0;
    for(tuple<int, int, int> edge : edges) {
        int a = get<0>(edge), b = get<1>(edge), c = get<2>(edge);
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b) {
            continue;
        }
        _union(a, b);
        total += c;
        last = c;
    }
    printf("%d\n", total - last);
    return 0;
}

int find(int x) {
    if(parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void _union(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    parent[root_a] = root_b;
}

bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<2>(a) < get<2>(b);
}