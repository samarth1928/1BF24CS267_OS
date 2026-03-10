#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], ct[n], visited[n];

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        visited[i] = 0;
    }

    while(completed < n) {
        int min = 9999;
        int index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && visited[i] == 0) {
                if(bt[i] < min) {
                    min = bt[i];
                    index = i;
                }
            }
        }

        if(index == -1) {
            time++;
        } else {
            ct[index] = time + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            time = ct[index];
            visited[index] = 1;
            completed++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    return 0;
}