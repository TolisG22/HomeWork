#include <stdio.h>
#include <stdlib.h>

int main() {
    float *sales = NULL;  
    int n = 10;           
    char sel;

    do {

        sales = (float*) malloc(n*sizeof(float));
        if (sales == NULL){
            printf("Memory not allocated\n");
            return 1;
        }

        printf("Give sales of %d markets\n", n);

        for (int i = 0; i<n; i++){
            printf("Sales of market %d:", i+1);
            scanf("%f", &sales[i]);
        }

        float sum = 0;
        for (int i=0; i<n; i++){
            sum += sales[i];
        }
        float mt = sum/n;
        printf("\n The average price of sales is: %.2f\n", mt);

        do{
            printf("\nSelection Menu:\n");
            printf("  r - Repeat the programm with new sales (10 markets)\n");
            printf("  a - New sales price (realloc)\n");
            printf("  e - Exit\n");
            printf("Selection: ");
            scanf(" %c", &sel);

            if (sel == 'a'){
                n++;
                float *temp = (float*) realloc(sales, n * sizeof(float));
                if (temp == NULL){
                    printf ("Memory re-allocation failed\n");
                    return 1;
                }
                sales = temp;
                printf("Give sales of the new market (No %d): ", n);
                scanf("%f", &sales[n-1]);

                sum = 0;
                for (int i=0; i<n; i++){
                    sum+=sales[i];
                }
                mt = sum/n;
                printf("The new average of sales is: %.2f\n", mt);
            }
            else if (sel == 'r'){
                free(sales);
                n=10;
                break;
            }
            else if (sel == 'e'){
                printf("Exitting program");
                free (sales);
            }
            else {
                printf("Not a valid selection. Try again.");
            }

        }while (sel != 'e' && sel != 'r');

        break;
        
    } while (1);

    return 0;

}