#include <stdio.h>

int main() {
    double income, tax;
    char payment;
    
    do {
        printf("Give your income: ");
        scanf("%lf", &income);

        if (income < 0) {
            printf("Invalid value! Income cannot be negative. \n");
        }

    } while (income < 0);
  
    if (income == 0) {
        tax = 0;
    }
    
    else if (income < 10000) {
        tax = income * 0.09;
    }
    else if (income < 20000) {
        tax = income * 0.22;
    }
    else if (income < 40000) {
        tax = income * 0.30;
    }
    else {
        tax = income * 0.50;
    }
    
    
    if ( income > 0 ){
        printf("Did the first moth payment completed? \n");
        scanf(" %c", &payment);
        if ( payment == 'y'){
            tax = tax * 0.1;
             printf("Tax is: %.2f€ \n",tax);
        }
        else if (payment == 'n'){
            printf("Tax is: %.2f€ \n",tax);
        }
        else{
            printf("Answer must be: y/n");
        }
    }
    else{
        printf("Tax is: %.2f€ \n",tax);
    }
    
    return 0;
}