#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    int matches;
    int goals;
} Player;

// 1ος τρόπος: επιστρέφει πίνακα 2 παικτών
Player* stats(Player p[], int N) {
    static Player result[2]; //Επειδή η μεταβλητή είναι τοπική το static βοηθάει στην ασφαλή συγκράτηση των στοιχείων στην main.

    Player maxGoals = p[0];
    Player maxAvg = p[0];
    double bestAvg = (p[0].matches == 0) ? 0.0 : (double)p[0].goals / p[0].matches; //Η χρησιμότητα των '?' και ':' έγινε γνωστή μέσω έρευνας στο διαδίκτυο.

    for (int i = 1; i < N; i++) {
        if (p[i].goals > maxGoals.goals)
            maxGoals = p[i];

        double avg = (p[i].matches == 0) ? 0.0 : (double)p[i].goals / p[i].matches;
        if (avg > bestAvg) {
            bestAvg = avg;
            maxAvg = p[i];
        }
    }

    result[0] = maxGoals;
    result[1] = maxAvg;
    return result;
}

// 2ος τρόπος: με αναφορά
void stats_ref(Player p[], int N, Player *maxGoals, Player *maxAvg) {
    *maxGoals = p[0];
    *maxAvg = p[0];
    double bestAvg = (p[0].matches == 0) ? 0.0 : (double)p[0].goals / p[0].matches;

    for (int i = 1; i < N; i++) {
        if (p[i].goals > maxGoals->goals) // Το '->' όπως είδαμε στο μάθημα αφού είναι pointer είναι σαν να γράφουμε 'maxGoals.goals'.
            *maxGoals = p[i];

        double avg = (p[i].matches == 0) ? 0.0 : (double)p[i].goals / p[i].matches;
        if (avg > bestAvg) {
            bestAvg = avg;
            *maxAvg = p[i];
        }

    }
}

int main() {
    int N;
    printf("How many players do you want? ");
    scanf("%d", &N);

    Player p[N];

    for (int i = 0; i < N; i++) {
        printf("\n   Player %d   \n", i + 1);
        printf("Name: ");
        scanf("%49s", p[i].name);
        printf("Age: ");
        scanf("%d", &p[i].age);
        printf("Matches: ");
        scanf("%d", &p[i].matches);
        printf("Goal: ");
        scanf("%d", &p[i].goals);
    }

    // Μέθοδος 1
    Player* bestp = stats(p, N);
    printf("\n    Results (Solution 1)    \n");
    printf("Most goals: %s (%d goals)\n", bestp[0].name, bestp[0].goals);
    printf("Best average goal/match: %s (%.2f goal/match)\n",
           bestp[1].name,
           (bestp[1].matches == 0) ? 0.0 : (double)bestp[1].goals / bestp[1].matches);

    // Μέθοδος 2
    Player p1, p2;
    stats_ref(p, N, &p1, &p2);
    printf("\n    Results (Solution 2)    \n");
    printf("Most goals: %s (%d goals)\n", p1.name, p1.goals);
    printf("Best average goal/match: %s (%.2f goal/match)\n",
           p2.name,
           (p2.matches == 0) ? 0.0 : (double)p2.goals / p2.matches);

    return 0;
}
