#include <stdio.h>

#define MAX 1000000

void push(int x);
int pop();
int size();
int empty();
int top_val();

int stack[MAX];
int top = -1;

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int cmd, x;
        scanf("%d", &cmd);

        switch (cmd) {
        case 1:
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            printf("%d\n", pop());
            break;
        case 3:
            printf("%d\n", size());
            break;
        case 4:
            printf("%d\n", empty());
            break;
        case 5:
            printf("%d\n", top_val());
            break;
        }
    }

    return 0;
}

void push(int x) {
    stack[++top] = x;
}

int pop(void) {
    if (top == -1) return -1;
    return stack[top--];
}

int size() {
    return top + 1;
}

int empty() {
    return top == -1 ? 1 : 0;
}

int top_val() {
    if (top == -1) return -1;
    return stack[top];
}
