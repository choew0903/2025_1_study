#include <stdio.h>
#include <string.h>

int main() {
    char arr[5][16]; // 최대 15글자 + 널문자까지
    int max_len = 0;

    // 5줄 입력받기
    for (int i = 0; i < 5; i++) {
        scanf("%s", arr[i]);
        int len = strlen(arr[i]);
        if (len > max_len) {
            max_len = len; // 가장 긴 줄의 길이 저장
        }
    }

    // 세로로 읽기
    for (int col = 0; col < max_len; col++) {
        for (int row = 0; row < 5; row++) {
            if (col < strlen(arr[row])) {
                printf("%c", arr[row][col]);
            }
        }
    }

    printf("\n"); // 마지막 줄바꿈
    return 0;
}
