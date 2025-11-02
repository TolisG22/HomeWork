#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 100

 typedef struct {
    char name[NAME_LEN];
    float salary;
} Employee;

int main (){
    int n;
    printf("How many employees will be imported? ");

    if (scanf("%d", &n) != 1 || n<=0){
        printf("Invalid number.\n");
        return 1;
    }

    Employee *arr=malloc(n*sizeof(Employee));
    if (arr==NULL){
        printf("Memory not allocated.\n");
        return 1;
    }

    for (int i=0; i<n; i++){
        printf("Employee %d\n", i+1);
        printf("Name:");
        scanf("%99s", arr[i].name);
        printf("Salary:");
        scanf("%f", &arr[i].salary);
    }

    printf("\n List of employees\n");
    for (int i = 0; i<n; i++){
        printf("Employee %d: Name: %s, Salary: %.2f\n", i+1, arr[i].name, arr[i].salary);
    }

    float total = 0.0f;
    for (int i=0; i<n; i++){
        total+=arr[i].salary;
    }

    printf("Total expences: %.2f\n", total);

    free(arr);
    return 0;
}