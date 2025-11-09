#include <stdio.h>

float calc(float a, float b, char symbol){
    if (symbol == '+')
        return a+b;
    else if (symbol == '-')
        return a-b;
    else if (symbol == '*')
        return a*b;
    else if (symbol == '/'){
        if (b==0){
            printf("Division by zero is not possible.\n");
            return 0;
        }
        return a/b;
    }
    else
        printf("Invalid symbol.\n");
}

int main(){
    float num1, num2, result;
    char symbol;

    while(1){
        printf("Enter a symbol(+, -, *, /) or 'e' to exit the proccess:\n");
        scanf("%c", &symbol);

        if (symbol == 'e'){
            printf("Exiting the proccess.\n");
            break;
        }

        printf("Enter 2 numbers so the proccess begins\n");
        scanf("%f %f", &num1, &num2);

        result = calc(num1, num2, symbol);

        if ((symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') && !(symbol == '/' && num2 == 0)) {
            printf("Result: %.2f\n\n", result);
        }
    }
    return 0;
}