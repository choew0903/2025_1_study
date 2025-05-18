#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum_of_part(char *part);

int main() {
    char input[100]; // 수식 입력받을 배열
    scanf("%s", input);

    int result = 0;
    char *token = strtok(input, "-"); // '-'를 기준으로 자름
    result = sum_of_part(token); // 첫 부분은 더해줌

    token = strtok(NULL, "-");
    while (token != NULL) {
        result -= sum_of_part(token); // 이후 부분은 더해서 빼줌
        token = strtok(NULL, "-");
    }

    printf("%d\n", result);
    return 0;
}

int sum_of_part(char *part) {
    int sum = 0;
    char *token = strtok(part, "+");
    while (token != NULL) {
        sum += atoi(token); // 문자열을 정수로 변환
        token = strtok(NULL, "+");
    }
    return sum;
}