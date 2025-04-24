// no.20040: 사이클 게임 (G4)

#include <cstdio>
#include <vector>
using namespace std;

int find(int x);
void _union(int a, int b);

vector<int> parent;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    parent.assign(n+1, 0);
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for(int i=1; i<=m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) {
            printf("%d\n", i);
            return 0;
        }
        else {
            _union(a, b);
        }
    }
    printf("0\n");
    return 0;
}

int find(int x) {
    if(parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void _union(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}