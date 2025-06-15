#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int* graph[MAX];      // 인접 리스트
int graph_size[MAX];  // 각 정점의 연결 정점 수
int visited[MAX];     // 방문 순서 저장
int order = 1;        // 현재 방문 순서

// 정렬용 비교 함수 (오름차순)
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void dfs(int v) {
    visited[v] = order++;  // 방문 순서 저장
    for (int i = 0; i < graph_size[v]; i++) {
        int next = graph[v][i];
        if (!visited[next])
            dfs(next);
    }
}

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // u -> v
        graph[u] = realloc(graph[u], sizeof(int) * (graph_size[u] + 1));
        graph[u][graph_size[u]++] = v;

        // v -> u
        graph[v] = realloc(graph[v], sizeof(int) * (graph_size[v] + 1));
        graph[v][graph_size[v]++] = u;
    }

    // 정점마다 오름차순 정렬
    for (int i = 1; i <= n; i++) {
        if (graph_size[i] > 1)
            qsort(graph[i], graph_size[i], sizeof(int), cmp);
    }

    dfs(r);

    // 1부터 n까지 방문 순서 출력
    for (int i = 1; i <= n; i++) {
        printf("%d\n", visited[i]);
    }

    return 0;
}
