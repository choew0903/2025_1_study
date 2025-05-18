#include <stdio.h>

#define MAX_LEN 600000

char S[MAX_LEN + 1];     // 최종 문자열을 담을 배열

// start 위치에서 길이 len 구간을 3등분하여 가운데 구간을 ' '로 바꾸고
// 양쪽 구간에 대해 재귀 호출
void cantor(int start, int len) {
    if (len < 3) return;               // 더 이상 분할 못 하면 종료
    int third = len / 3;
    // 가운데 구간을 공백으로
    for (int i = start + third; i < start + 2*third; i++) {
        S[i] = ' ';
    }
    // 양쪽 구간 재귀 분할
    cantor(start, third);
    cantor(start + 2*third, third);
}

int main() {
    int N;
    // 입력이 끝날 때까지 (EOF) 반복
    while (scanf("%d", &N) == 1) {
        // 길이 3^N 계산
        int len = 1;
        for (int i = 0; i < N; i++) len *= 3;
        // 초기화: 모두 '-'로 채우기
        for (int i = 0; i < len; i++) {
            S[i] = '-';
        }
        // 문자열 끝 표시
        S[len] = '\0';
        // 칸토어 집합 분할·공백 처리
        cantor(0, len);
        // 결과 출력
        printf("%s\n", S);
    }
    return 0;
}
