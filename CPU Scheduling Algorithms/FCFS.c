#include<stdio.h>

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[], int rt[], int at[]) {
    int i;
    wt[0] = 0;
    rt[0] = 0;

    for (i = 1; i < n ; i++)
        wt[i] =  bt[i-1] + wt[i-1] - at[i];

    for (i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];

    for (i = 1; i < n; i++)
        rt[i] = wt[i];
}

void findAvgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], rt[n];

    findTurnaroundTime(processes, n, bt, wt, tat, rt, at);

    printf("Processes   Burst time   Arrival time    Waiting time   Turnaround time   Response time\n");

    int total_wt = 0, total_tat = 0, total_rt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        total_rt += rt[i];
        printf(" %d ", processes[i]);
        printf("          %d ", bt[i]);
        printf("           %d", at[i]);
        printf("               %d", wt[i]);
        printf("                %d", tat[i]);
        printf("                %d\n", rt[i]);
    }

    printf("Average waiting time = %f", (float)total_wt / (float)n);
    printf("\nAverage turnaround time = %f", (float)total_tat / (float)n);
    printf("\nAverage response time = %f", (float)total_rt / (float)n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    for (int i = 0; i < n; i++)
        processes[i] = i + 1;

    int burst_time[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    int arrival_time[n];
    printf("Enter arrival time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    findAvgTime(processes, n, burst_time, arrival_time);
    return 0;
}
