#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];

  
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; 
    }

    while(completed < n) {
        int min = 9999;
        int index = -1;

       
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(index == -1 || rt[i] < min || 
                   (rt[i] == min && at[i] < at[index])) {
                    min = rt[i];
                    index = i;
                }
            }
        }

        if(index == -1) {
            time++;
        } else {
            rt[index]--;
            time++;

            if(rt[index] == 0) {
                completed++;
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    return 0;
}