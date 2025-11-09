#include <stdio.h>
#include <stdlib.h>

float min(float arr[], int N){
    float temp=arr[0];
    for (int i=1; i<N; i++){
        if (arr[i]<temp){
            temp = arr[i];
        }
    }
    return temp;
}

float max(float arr[], int N){
    float temp = arr[0];
    for (int i=1; i<N; i++){
        if (arr[i]>temp){
            temp = arr[i];
        }
    }
    return temp;
}

void minmax(float arr[], int N, float xmin, float xmax){
    
    if (xmax==xmin){
        for (int i=0; i<N; i++){
            arr[i] = 0.0;
        }
        return;
    }

    for (int i=0; i<N; i++){
        arr[i]=(arr[i] - xmin)/(xmax-xmin);
        printf("The new value is %.2f\n", arr[i]);
    }
}


int main(){
    int N;

    printf("Give the size of the array.\n");
    scanf("%d", &N);

    if (N<=0){
        printf("The size of the array should be at least 1\n");
        return 1;
    }

    float* arr = (float*) malloc(N * sizeof(float));
    if (arr == NULL){
        printf("Creation failed.\n");
        return 1;
    }

    for (int i=0; i<N; i++){
        printf("Give the value of the cell %d\n", i+1);
        scanf("%f", &arr[i]);
    }

    float minValue = min(arr,N);
    float maxValue = max(arr,N);

    printf("The max value is %.2f\n", maxValue);
    printf("The min value is %.2f\n", minValue);

    minmax (arr,N, minValue, maxValue);
    free(arr);

    return 0;
}