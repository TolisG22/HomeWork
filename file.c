#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int N, i;
    int *goals;       
    int sum = 0;
    double mo;

    
    fp = fopen("gkol.txt", "r");
    if (fp == NULL) {
        printf("Error: The file gkol.txt not found\n");
        return 1;
    }

    
    fscanf(fp, "%d", &N);

    
    goals = (int *) malloc(N * sizeof(int));
    if (goals == NULL) {
        printf("Malloc failed.\n");
        fclose(fp);
        return 1;
    }

    
    for (i = 0; i < N; i++) {
        fscanf(fp, "%d", &goals[i]);
        sum += goals[i];
    }

    fclose(fp);

    
    mo = (double)sum / N;

    
    printf("Matches: %d\n", N);
    printf("Goal/Match: ");
    for (i = 0; i < N; i++) {
        printf("%d ", goals[i]);
    }
    printf("\nAverage: %.2f\n", mo);

    
    free(goals);

    return 0;
}
