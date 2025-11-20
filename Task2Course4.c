#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2000000   


void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int main() {
    int *A = malloc(N * sizeof(int));
    int *B = malloc(N * sizeof(int));
    int *C = malloc(N * sizeof(int));

    srand(time(NULL));

    
    for (int i = 0; i < N; i++) {
        int x = rand();
        A[i] = x;
        B[i] = x;
        C[i] = x;
    }

    clock_t start, end;
    double time_bubble, time_quick, time_merge;

    
    printf("Starting bubble sort \n");
    start = clock();
    bubbleSort(A, N);
    end = clock();
    time_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %.3f sec\n", time_bubble);

    printf("Starting Quick Sort \n");
    start = clock();
    quickSort(B, 0, N - 1);
    end = clock();
    time_quick = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: %.3f sec\n", time_quick);

    printf("Starting Merge Sort \n");
    start = clock();
    mergeSort(C, 0, N - 1);
    end = clock();
    time_merge = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort Time: %.3f sec\n", time_merge);

    free(A);
    free(B);
    free(C);

    return 0;
}
