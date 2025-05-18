#include <stdio.h>
#include <string.h>

#define MAX 2000000


int queue[MAX];
int front_idx = 0;
int back_idx = 0;

void push(int x);
int pop();
int size();
int empty();
int front();
int back();

int main() {
    int N;
    char cmd[10];
    int x;

    scanf("%d", &N);

    while (N--) {
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            scanf("%d", &x);
            push(x);
        }
        else if (strcmp(cmd, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", front());
        }
        else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", back());
        }
    }

    return 0;
}

void push(int x) {
    queue[back_idx++] = x;
}
int pop() {
    if (front_idx == back_idx) return -1;
    return queue[front_idx++];
}
int size() {
    return back_idx - front_idx;
}
int empty() {
    return front_idx == back_idx ? 1 : 0;
}
int front() {
    if (front_idx == back_idx) return -1;
    return queue[front_idx];
}
int back() {
    if (front_idx == back_idx) return -1;
    return queue[back_idx - 1];
}