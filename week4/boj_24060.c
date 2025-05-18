#include <stdio.h>

int A[1001], tmp[1001];
int N, K, cnt = 0, result = -1;

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, t = l;
    // 두 부분 배열 병합
    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else               tmp[t++] = A[j++];
    }
    while (i <= mid) tmp[t++] = A[i++];
    while (j <= r)   tmp[t++] = A[j++];
    // tmp를 A로 복사하며 카운트
    for (int k = l; k <= r; k++) {
        A[k] = tmp[k];
        cnt++;
        if (cnt == K) result = A[k];
    }
}

void merge_sort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, mid, r);
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    merge_sort(0, N - 1);
    printf("%d", result);
    return 0;
}
