// Task 1: NFL score combinations 
#include <stdio.h>

int main(void) {
    int score, read_ok;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        read_ok = scanf("%d", &score);

        if (read_ok != 1) {
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }
        if (score == 1) break;
        if (score < 1) { printf("Invalid score.\n"); continue; }

        int found_any = 0;
        for (int a = 0; a <= score / 8; a++) {              // TD+2 (8)
            for (int b = 0; b <= score / 7; b++) {          // TD+FG (7)
                for (int c = 0; c <= score / 6; c++) {      // TD (6)
                    for (int d = 0; d <= score / 3; d++) {  // FG (3)
                        int used = 8*a + 7*b + 6*c + 3*d;
                        int rem = score - used;
                        if (rem < 0 || (rem % 2) != 0) continue; // Safety is 2
                        int e = rem / 2; // Safety (2)

                        if (!found_any) {
                            printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
                        }
                        found_any = 1;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               a, b, c, d, e);
                    }
                }
            }
        }
        if (!found_any) printf("No combinations found.\n");
    }
    return 0;
}
