#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n, long long *comparisons, long long *assignments) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];           (*assignments)++;
                arr[j] = arr[j + 1];     (*assignments)++;
                arr[j + 1] = temp;       (*assignments)++;
            }
        }
    }
}

void selection_sort(int arr[], int n, long long *comparisons, long long *assignments) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        temp = arr[min_idx];     (*assignments)++;
        arr[min_idx] = arr[i];   (*assignments)++;
        arr[i] = temp;           (*assignments)++;
        
    }
}

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

void copy_array(int cp[], int mainArr[], int n) {
    for (int i = 0; i < n; i++)
        cp[i] = mainArr[i];
}

int main() {
    srand(time(NULL));

    int sizes[] = {100, 1000, 10000, 100000, 1000000};
    int numSizes = 5;

    printf("SIZE\tBUBBLE OPS\tSELECTION OPS\tBUBBLE TIME\tSELECTION TIME\n");

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];

        int *arr = malloc(n * sizeof(int));
        int *copy = malloc(n * sizeof(int));

        generate_random_array(arr, n);

        long long bubble_comps = 0, bubble_assigns = 0;
        long long sel_comps = 0, sel_assigns = 0;

        copy_array(copy, arr, n);
        clock_t t1 = clock();
        bubble_sort(copy, n, &bubble_comps, &bubble_assigns);
        clock_t t2 = clock();
        double bubble_time = (double)(t2 - t1) / CLOCKS_PER_SEC;

        copy_array(copy, arr, n);
        clock_t t3 = clock();
        selection_sort(copy, n, &sel_comps, &sel_assigns);
        clock_t t4 = clock();
        double sel_time = (double)(t4 - t3) / CLOCKS_PER_SEC;

        long long bubble_total_ops = bubble_comps + bubble_assigns;
        long long sel_total_ops = sel_comps + sel_assigns;

        printf("%d\t%lld\t%lld\t%.6f\t%.6f\n", n, bubble_total_ops, sel_total_ops, bubble_time, sel_time);

        free(arr);
        free(copy);
    }

    return 0;
}
