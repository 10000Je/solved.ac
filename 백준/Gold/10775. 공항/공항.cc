// no.10775: 공항

#include <iostream>
#include <vector>
using namespace std;

int parent[(int)(1e5)+1];

int find(int x);
void _union(int a, int b);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int G, P;
    cin >> G >> P;
    // init
    for(int i=1; i<=G; i++) {
        parent[i] = i;
    }
    
    int count = 0;
    for(int i=0; i<P; i++)
    {
        int gi;
        cin >> gi;
        if(find(gi) == 0)
            break;
        int root_gi = find(gi);
        _union(root_gi-1, root_gi);
        count++;
    }
    cout << count << '\n';
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