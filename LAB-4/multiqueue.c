#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int PID[20], AT[20], BT[20], TYPE[20];
    int CT[20], TAT[20], WT[20], START[20];
    int done[20] = {0};

    printf("Enter PID, Arrival Time, Burst Time, Type (0=System,1=User):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &PID[i], &AT[i], &BT[i], &TYPE[i]);
        CT[i] = TAT[i] = WT[i] = START[i] = 0;
    }

    int time = 0, completed = 0;

    while (completed < n) {
        int chosen = -1;


        for (int i = 0; i < n; i++) {
            if (!done[i] && TYPE[i] == 0 && AT[i] <= time) {
                chosen = i;
                break;
            }
        }


        if (chosen == -1) {
            for (int i = 0; i < n; i++) {
                if (!done[i] && TYPE[i] == 1 && AT[i] <= time) {
                    chosen = i;
                    break;
                }
            }
        }


        if (chosen == -1) {
            int nextArrival = 9999;
            for (int i = 0; i < n; i++) {
                if (!done[i] && AT[i] < nextArrival) {
                    nextArrival = AT[i];
                }
            }
            time = nextArrival;
            continue;
        }

        START[chosen] = time;
        time += BT[chosen];
        CT[chosen] = time;
        TAT[chosen] = CT[chosen] - AT[chosen];
        WT[chosen] = TAT[chosen] - BT[chosen];
        done[chosen] = 1;
        completed++;
    }


    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%s\t%d\t%d\t%d\n",
               PID[i], AT[i], BT[i],
               (TYPE[i] == 0 ? "SYS" : "USR"),
               CT[i], TAT[i], WT[i]);
    }

    return 0;
}
