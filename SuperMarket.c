#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int N;
    printf("How many years you want to have on memory?");
    scanf("%d", &N);

    char* months[12] = {"January", "February", "March", "April", "May", "June", "July","August", "September", "October", "November", "December"};
    int sales[N][12][5];
    float mo[12];
    float marketMo[5];
    for (int year=0; year<N; year++){
        for (int month=0; month<12; month++){
            int sum=0;
            for (int market=0; market<5; market++){
                sales[year][month][market] = 10000 + rand() % 1000001;
                sum+= sales[year][month][market];
            }
            mo[month] = sum/5.0;
        }

        printf("Average per month:\n\n");
        for (int month = 0; month < 12; month++) {
            printf("%s: ", months[month]);
            for (int market = 0; market < 5; market++) {
                printf("%d ", sales[year][month][market]);
            }
            printf(" Average: %.2f\n", mo[month]);
        }

        for (int market=0; market<5; market++){
            int sum=0;
            for (int month=0; month<12; month++){
                sum+= sales[year][month][market];
            }
            marketMo[market]=sum/12.0;
        }

        printf("\nAverage per market:\n");
        for (int market = 0; market < 5; market++) {
            printf("Market %d: %.2f\n", market + 1, marketMo[market]);
        }

    
        int bestmarket = 0;
        float maxSales = marketMo[0];

        for (int market = 1; market < 5; market++) {
            if (marketMo[market] > maxSales) {
                maxSales = marketMo[market];
                bestmarket = market;
            }
        }

        printf("\nThe market with the most sales is market %d with an average of %.2f\n", 
        bestmarket + 1, maxSales);

        int bestMonth = 0;
        int maxSalesMonth = 0;

        for (int month = 0; month < 12; month++) {
            int total = 0;
            for (int market = 0; market < 5; market++) {
            total += sales[year][month][market];
            }

            if (total > maxSalesMonth) {
            maxSalesMonth = total;
            bestMonth = month;
            }
        }

        printf("\nMonth with the most sales is %s with total %d\n", 
       months[bestMonth], maxSalesMonth);
    }
    return 0;
}