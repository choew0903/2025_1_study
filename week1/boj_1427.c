#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void select(int arr[], int n);

int compare(void* a, void* b);

int main() {

   int a[1000] = { 0 };
   int i, num;

   scanf("%d", &num);

   for (i = 0; num > 0; i++) {
      a[i] = num % 10;
      num /= 10;
   }

    select(a, i);

   for (int j = 0; j < i; j++) {
      printf("%d", a[j]);
   }

   return 0;
}

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