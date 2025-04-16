// no.1992: 쿼드트리

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int is_one(int r, int c, int n);
int is_zero(int r, int c, int n);
void select(int r, int c, int n);
void quad_tree(int r, int c, int n);

int board[64][64];

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char str[100];
    for(int i=0; i<n; i++) {
        scanf("%s", str);
        for(int j=0; str[j]!=0; j++) {
            board[i][j] = str[j]-'0';
        }
    }
    quad_tree(0, 0, n);
    printf("\n");
    return 0;
}

void quad_tree(int r, int c, int n) {
    if(is_one(r, c, n) || is_zero(r, c, n)) {
        printf("%d", board[r][c]);
        return;
    }
    printf("(");
    select(r, c, n/2);
    select(r, c+n/2, n/2);
    select(r+n/2, c, n/2);
    select(r+n/2, c+n/2, n/2);
    printf(")");
}

void select(int r, int c, int n) {
    if(is_one(r, c, n))
        printf("1");
    else if(is_zero(r, c, n))
        printf("0");
    else
        quad_tree(r, c, n);
}

int is_one(int r, int c, int n) {
    for(int i=r; i<r+n; i++)
        for(int j=c; j<c+n; j++)
            if(board[i][j] == 0)
                return FALSE;
    return TRUE;
}

int is_zero(int r, int c, int n) {
    for(int i=r; i<r+n; i++)
        for(int j=c; j<c+n; j++)
            if(board[i][j] == 1)
                return FALSE;
    return TRUE;
}