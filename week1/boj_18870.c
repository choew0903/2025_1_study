#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int compare(void* a, void* b);
int unique(int* arr, int size);
int find(int arr[], int n, int key);


int main() {
   
   int n;
   int arr[1000000];
   int sort[1000000];

   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   for (int i = 0; i < n; i++) {
      sort[i] = arr[i];
   }
   
   qsort(arr, n, sizeof(int), compare);

   int cnt = unique(arr, n);
   for (int i = 0; i < n; i++) {
      printf("%d ", find(arr, cnt, sort[i]));
   }
   return 0;
}

int compare(void* a, void* b) {
   int A = *(int*)a;
   int B = *(int*)b;

   if (A > B)return 1;
   else if (A == B)return 0;
   else return -1;
}

int unique(int* arr, int size) {
   int i, j = 0;
   for (i = 1; i < size; i++) {
      if (arr[j] == arr[i]) continue;
      arr[++j] = arr[i];
   }
   return ++j;
}

int find(int arr[], int n, int key) {

   int mid;
   int low = 0;
   int high = n - 1;

   while (low <= high) {
      mid = (low + high) / 2;
      if (arr[mid] == key) return mid;
      else if (key < arr[mid]) high = mid - 1;
      else if (key > arr[mid]) low = mid + 1;
   }
   return -1;
}
