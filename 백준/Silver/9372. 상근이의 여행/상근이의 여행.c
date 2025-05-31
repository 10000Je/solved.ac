// no.9372: 상근이의 여행

#include <stdio.h>

typedef struct Edge
{
    int a;
    int b;
} Edge;

Edge list[10000];

int parent[1001];

// find x's root node
int find(int x);

// union a and b set
void _union(int a, int b);

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++)
            parent[i] = i;

        for(int i=0; i<m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            list[i].a = a;
            list[i].b = b;
        }
        
        int count = 0;
        for(int i=0; i<m; i++)
        {
            int a = list[i].a;
            int b = list[i].b;
            if(find(a) == find(b))
                continue;
            count++;
            _union(a, b);
        }
        printf("%d\n", count);
    }
    return 0;
}

int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void _union(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);
    parent[root_b] = root_a;
}