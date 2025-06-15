#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int* graph[MAX];      // 인접 리스트
int graph_size[MAX];  // 연결 정점 수
int visited[MAX];     // 방문 순서 저장
int queue[MAX];       // 큐
int front = 0, rear = 0;
int order = 1;

// 오름차순 정렬 함수
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// 큐에 정점 추가
void enqueue(int v) {
    queue[rear++] = v;
}

// 큐에서 정점 꺼냄
int dequeue() {
    return queue[front++];
}

int is_empty() {
    return front == rear;
}

void bfs(int start) {
    enqueue(start);
    visited[start] = order++;

    while (!is_empty()) {
        int current = dequeue();

        for (int i = 0; i < graph_size[current]; i++) {
            int next = graph[current][i];
            if (!visited[next]) {
                visited[next] = order++;
                enqueue(next);
            }
        }
    }
}

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    // 간선 입력
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

    // 오름차순 정렬
    for (int i = 1; i <= n; i++) {
        if (graph_size[i] > 1)
            qsort(graph[i], graph_size[i], sizeof(int), cmp);
    }

    bfs(r);  // BFS 실행

    // 방문 순서 출력
    for (int i = 1; i <= n; i++) {
        printf("%d\n", visited[i]);
    }

    return 0;
}
