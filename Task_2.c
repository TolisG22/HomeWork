#include <stdio.h>

// Παρακάτω εισάγω την math.h ώστε να μπορώ να χρησιμοποιήσω την pow για την δύναμη.

#include <math.h> 

int main() {
    double L, x, f = 0;
    int N, i;

    printf("Give L: ");
    scanf("%lf", &L);

    printf("Give x: ");
    scanf("%lf", &x);

    do {
        printf("Give N (0 < N < 10): ");
        scanf("%d", &N);
        if (N <= 0 || N >= 10) {
            printf("Invalid input. Try again.\n");
        }
    } while (N <= 0 || N >= 10);

    
    for (i = 0; i <= N; i++) {
        f = f + pow(x, i) + (i / (float)N);
    }

    f = f * L; 

    printf("Η τιμή της συνάρτησης είναι: %.3f\n", f);

    return 0;
}
