#include <stdio.h>
#include <stdlib.h>

int sum(int arr[], int N){
    int sum = 0;
    for (int i=0; i<N; i++){
        sum+=arr[i];
    }
    return sum;
}

int sum2(int arr[], int N){
    if (N == 1)   
        return arr[0];
    else           
        return arr[N-1] + sum2(arr, N-1);
}

int main(){
    int N;
    printf("How many cells do you want?\n");
    scanf("%d", &N);

    int* arr = (int*) malloc(N*sizeof(int));

    for (int i=0; i<N; i++){
        printf("Give the value of the cell %d\n", i+1);
        scanf("%d", &arr[i]);
    }

    int summary = sum(arr, N);
    printf("The summary of the cells values is: %d\n", summary);

    summary = sum2(arr, N);
    printf("The summary of the cells values with recurse is: %d\n", summary);

    return 0;
}