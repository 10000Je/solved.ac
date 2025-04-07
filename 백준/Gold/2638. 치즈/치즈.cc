// no.2638: 치즈 (G3)

#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

int grid[100][100];
int n, m;

bool isEmpty();
void bfs();

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    int t = 0;
    while(!isEmpty()) {
        bfs();
        t++;
    }
    printf("%d\n", t);
    return 0;
}

bool isEmpty() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void bfs() {
    int count[100][100];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            count[i][j] = 0;
        }
    }
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    count[0][0] = -1;
    while(!que.empty()) {
        pair<int, int> x = que.front();
        int i = x.first, j = x.second;
        que.pop();
        vector<pair<int, int>> nodes = {
            make_pair(i-1, j), make_pair(i+1, j), make_pair(i, j-1), make_pair(i, j+1)
        };
        for(pair<int, int> node : nodes) {
            int r = node.first, c = node.second;
            if(r<0 || r>=n || c<0 || c>=m) {
                continue;
            }
            if(grid[r][c] == 1) {
                count[r][c]++;
                continue;
            }
            if(count[r][c] == 0) {
                count[r][c] = -1;
                que.push(make_pair(r, c));
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1 && count[i][j] >= 2) {
                grid[i][j] = 0;
            }
        }
    }
}