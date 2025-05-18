#include <stdio.h>
#define MAX 2000000

int deque[MAX];
int front_idx = MAX / 2;
int back_idx = MAX / 2;

void push_front(int x);
void push_back(int x);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int cmd, x;
        scanf("%d", &cmd);

        switch (cmd) {
            case 1:
                scanf("%d", &x);
                push_front(x);
                break;
            case 2:
                scanf("%d", &x);
                push_back(x);
                break;
            case 3:
                printf("%d\n", pop_front());
                break;
            case 4:
                printf("%d\n", pop_back());
                break;
            case 5:
                printf("%d\n", size());
                break;
            case 6:
                printf("%d\n", empty());
                break;
            case 7:
                printf("%d\n", front());
                break;
            case 8:
                printf("%d\n", back());
                break;
        }
    }

    return 0;
}

void push_front(int x) {
    deque[--front_idx] = x;
}

void push_back(int x) {
    deque[back_idx++] = x;
}

int pop_front() {
    if (front_idx == back_idx) return -1;
    return deque[front_idx++];
}

int pop_back() {
    if (front_idx == back_idx) return -1;
    return deque[--back_idx];
}

int size() {
    return back_idx - front_idx;
}

int empty() {
    return front_idx == back_idx ? 1 : 0;
}

int front() {
    if (front_idx == back_idx) return -1;
    return deque[front_idx];
}

int back() {
    if (front_idx == back_idx) return -1;
    return deque[back_idx - 1];
}
