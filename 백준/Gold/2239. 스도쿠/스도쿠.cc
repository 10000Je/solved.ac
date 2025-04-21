// no.2239: 스도쿠 (G4)

#include <cstdio>
#include <vector>
#include <functional>
using namespace std;

int board[9][9];
vector<pair<int, int>> blank;
bool over = false;

void dfs(int i);
bool isDuplicated(int i, int num);

int main() {
    for(int i=0; i<9; i++) {
        char str[10];
        scanf("%s", str);
        for(int j=0; j<9; j++) {
            board[i][j] = str[j] - '0';
            if(board[i][j] == 0) {
                blank.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0);
    return 0;
}

void dfs(int i) {
    if(over) {
        return;
    }
    if(i == blank.size()) {
        over = true;
        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                printf("%d", board[r][c]);
            }
            printf("\n");
        }
        return;
    }
    int r = blank[i].first, c = blank[i].second;
    for(int num=1; num<10; num++) {
        if(isDuplicated(i, num)) {
            continue;
        }
        board[r][c] = num;
        dfs(i+1);
        board[r][c] = 0;
    }

}

bool isDuplicated(int i, int num) {
    int r = blank[i].first, c = blank[i].second;
    for(int i=0; i<9; i++) {
        if(board[r][i] == num || board[i][c] == num) {
            return true;
        }
    }
    int ist = r-r%3, jst = c-c%3;
    for(int i=ist; i<ist+3; i++) {
        for(int j=jst; j<jst+3; j++) {
            if(board[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}