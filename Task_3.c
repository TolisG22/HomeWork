#include <stdio.h>

int main()
{
    float a, b, result;
    char operation;
    int counter = 0;
    
    printf("Enter $ as operation to exit.\n");

    while (operation != '$'){
        printf("\nEnter a, b and operation (+, -, *, /): ");
        scanf("%f %f %c", &a, &b, &operation);

        if (operation == '$') {
            printf("Exiting calculator. Valid calculations: %d.\n", counter);
            continue;
        }

        if (operation == '/' && b == 0.0){
            printf("Error: Cannot divide by 0.0. Operation has failed. Valid calculations: %d.\n", counter);
            return -1;
        }

        if (operation == '+'){
            result = a + b;
        }
        else if (operation == '-'){
            result = a - b;
        }
        else if (operation == '*'){
            result = a * b;
        }
        else{

            if (operation != '/'){
                printf("Error: undefined operation: %c", operation);
                return -1;
            }

            result = a / b;
        }

        counter++;

        printf("Success! Result of %f %c %f = %f \n", a, operation, b, result);
        printf("Valid calculations: %d.\n", counter);
    }

    return 0;

}