// no.16724: 피리 부는 사나이 (G3)

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> parent[1000][1000];

pair<int, int> find(pair<int, int> x);
void _union(pair<int, int> a, pair<int, int> b);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    // init
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            parent[i][j] = make_pair(i, j);
        }
    }
    // union_find
    for(int i=0; i<n; i++) {
        string row;
        cin >> row;
        for(int j=0; j<row.length(); j++) {
            switch(row[j]) {
                case 'D':
                    _union(make_pair(i, j), make_pair(i+1, j));
                    break;
                case 'U':
                    _union(make_pair(i, j), make_pair(i-1, j));
                    break;
                case 'L':
                    _union(make_pair(i, j), make_pair(i, j-1));
                    break;
                case 'R':
                    _union(make_pair(i, j), make_pair(i, j+1));
                    break;
            }
        } 
    }
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(parent[i][j] == make_pair(i, j))
                count++;
        }
    }
    cout << count << '\n';
    return 0;
}

pair<int, int> find(pair<int, int> x) {
    int r = x.first, c = x.second;
    if(parent[r][c] != make_pair(r, c)) {
        parent[r][c] = find(parent[r][c]);
    }
    return parent[r][c];
}

void _union(pair<int, int> a, pair<int, int> b) {
    pair<int, int> root_a = find(a);
    pair<int, int> root_b = find(b);
    parent[root_b.first][root_b.second] = root_a;
}