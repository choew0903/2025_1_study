#include <stdio.h>

int fib(int n) {
    if (n < 2)       // n이 0 또는 1이면
        return n;    // 그대로 반환
    return fib(n-1) + fib(n-2);  // 그 외에는 앞 두 수 합
}

int main() {
    int n;
    scanf("%d", &n);          // 입력 받기
    printf("%d", fib(n));     // 결과 출력
    return 0;
}
