#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(void* a, void* b);
int search(char arr[][21], int n, char key[]);

int main() {

   int n, m;
   char arr_1[500000][21];
   char arr_2[500000][21];
   char result[500000][21];


   //듣도 못한 사람
   scanf("%d", &n); 
   scanf("%d", &m);
   for (int i = 0; i < n; i++) {
      scanf("%s", &arr_1[i]);
   }

   //보도 못한 사람
   for (int i = 0; i < m; i++) {
      scanf("%s", &arr_2[i]);
   }

   qsort(arr_1, n, sizeof(arr_1[0]), compare); //arr_1을 오름차순으로 정렬

   int count = 0;

   // 두 배열 목록에서 겹치는 이름을 찾아서 결과 배열에 저장
   for (int i = 0; i < m; i++) {
      if (search(arr_1, n, arr_2[i]) != -1) {
         strcpy(result[count], arr_2[i]);
         count++;
      }
   }

   qsort(result, count, sizeof(result[0]), compare); //결과 배열 오름차순으로 정렬렬

   printf("%d\n", count);
   for (int i = 0; i < count; i++) {
      printf("%s\n", result[i]);
   }

   return 0;

}

//문자열 비교함수
int compare(void* a, void* b) {

   return strcmp((char*)a, (char*)b);
}

//이진 탐색 함수
int search(char arr[][21], int n, char key[]) {
   int mid;
   int low = 0;
   int high = n - 1;
   
   while (low <= high) {
      mid = (low + high) / 2;
      int cmp = strcmp(arr[mid],key);

      if (cmp==0) return mid;
      else if (cmp < 0) low = mid + 1;
      else if (cmp > 0) high = mid - 1;
   }
   return -1;
}