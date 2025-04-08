// no.16236: 아기 상어 (G3)

#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#define INF int(1e8)
using namespace std;

int n;
int total = 0;
int space[20][20];

struct {
    int r;
    int c;
    int size;
    int guage;
} shark;

bool bfs();

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int state;
            scanf("%d", &state);
            if(state == 9) {
                shark.r = i;
                shark.c = j;
                shark.size = 2;
                shark.guage = 0;
                space[i][j] = 0;
            }
            else {
                space[i][j] = state;
            }
        }
    }
    vector<vector<int>> dist;
    while(bfs());
    printf("%d\n", total);
    return 0;
}

bool bfs() {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    queue<pair<int, int>> que;
    int min = INF;
    pair<int, int> loc;
    dist[shark.r][shark.c] = 0;
    que.push(make_pair(shark.r, shark.c));
    while(!que.empty()) {
        int r = que.front().first, c = que.front().second;
        que.pop();
        vector<pair<int, int>> nodes = {
            make_pair(r-1, c), make_pair(r, c-1), make_pair(r, c+1), make_pair(r+1, c)
        };
        for(pair<int, int> node : nodes) {
            int i = node.first, j = node.second;
            if(i<0 || i>=n || j<0 || j>=n) {
                continue;
            }
            if(dist[i][j] != INF) {
                continue;
            }
            if(space[i][j] > shark.size) {
                continue;
            }
            dist[i][j] = dist[r][c] + 1;
            if(space[i][j] == 0 || space[i][j] == shark.size) {
                que.push(make_pair(i, j));
            }
            else if(min == INF) {
                min = dist[i][j];
                loc = make_pair(i, j);
            }
            else if(dist[i][j] == min) {
                pair<int, int> pr = make_pair(i, j);
                if(pr < loc) {
                    loc = pr;
                }
            }
        }
    }
    if(min == INF) {
        return false;
    }
    else {
        shark.r = loc.first;
        shark.c = loc.second;
        shark.guage++;
        if(shark.guage == shark.size) {
            shark.guage = 0;
            shark.size++;
        }
        space[loc.first][loc.second] = 0;
        total += dist[loc.first][loc.second];
        return true;
    }
}
