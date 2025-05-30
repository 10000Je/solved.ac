#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100001

int graph[MAX];         // 각 학생이 선택한 학생
bool visited[MAX];      // 방문 여부
bool finished[MAX];     // DFS가 끝났는지 여부
int count;              // 사이클에 포함된 학생 수

void dfs(int node) {
    visited[node] = true;
    int next = graph[node];

    if (!visited[next]) {
        dfs(next);
    } else if (!finished[next]) {
        // 사이클 발견
        for (int i = next; i != node; i = graph[i]) {
            count++;
        }
        count++; // 현재 노드도 포함
    }

    finished[node] = true;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &graph[i]);
            visited[i] = false;
            finished[i] = false;
        }

        count = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        printf("%d\n", n - count);
    }

    return 0;
}