#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], rt[n], visited[n];
    float total_tat = 0, total_wt = 0;

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        visited[i] = 0;
    }

    while(completed < n) {
        int min_bt = INT_MAX;
        int index = -1;

        // Find shortest job among arrived processes
        for(i = 0; i < n; i++) {
            if(at[i] <= time && visited[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    index = i;
                }
            }
        }

        if(index != -1) {
            rt[index] = time - at[index];
            time += bt[index];
            ct[index] = time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            total_tat += tat[index];
            total_wt += wt[index];

            visited[index] = 1;
            completed++;
        }
        else {
            time++; // If no process has arrived
        }
    }

    // Output
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);

    return 0;
}
