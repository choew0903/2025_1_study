#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void select(int arr[], int n);


int main(){
   int n;
   int k;
   int x[10000];
   
   scanf("%d %d", &n, &k);

   for (int i = 0; i < n; i++) {
      scanf("%d", &x[i]);
   }

   select(x, n);

   printf("%d", x[k-1]);

   
   return 0;
}

//선택정렬 함수 정의
void select(int arr[], int n) {
   int i, j, maxidx, temp;
   for (i = 0; i < n - 1; i++) {
      maxidx = i;
      for (j = i + 1; j < n; j++) {
         if (arr[j] > arr[maxidx]) {
            maxidx = j;
         }
      }
      temp = arr[i];
      arr[i] = arr[maxidx];
      arr[maxidx] = temp;
   }
}