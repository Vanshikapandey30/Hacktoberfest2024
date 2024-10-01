#include <stdio.h>

struct Process {
    int pid; 
    int burst_time; 
    int arrival_time; 
    int remaining_time;
    int waiting_time; 
    int turnaround_time;
    int response_time; 
    int completed;
};

int findShortestRemainingTime(struct Process processes[], int n, int current_time) {
    int shortest = -1;
    int shortest_time = 9999; 

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && !processes[i].completed) {
            if (processes[i].remaining_time < shortest_time) {
                shortest_time = processes[i].remaining_time;
                shortest = i;
            }
        }
    }

    return shortest;
}

void calculateTimes(struct Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        int shortest = findShortestRemainingTime(processes, n, current_time);

        if (shortest == -1) {
            printf("No process available at time %d\n", current_time);
            current_time++;
            continue;
        }

        if (processes[shortest].response_time == -1) {
            processes[shortest].response_time = current_time - processes[shortest].arrival_time;
        }

        processes[shortest].remaining_time--;
        current_time++;

        if (processes[shortest].remaining_time == 0) {
            processes[shortest].completed = 1;
            completed_processes++;

            processes[shortest].waiting_time = current_time - processes[shortest].arrival_time - processes[shortest].burst_time;
            processes[shortest].turnaround_time = current_time - processes[shortest].arrival_time;

            printf("Process %d completed at time %d\n", processes[shortest].pid, current_time);
        }
    }
}

void displayProcessDetails(struct Process processes[], int n) {
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tResponse Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time,
               processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = 0;
        processes[i].response_time = -1; 
    }

    calculateTimes(processes, n);

    printf("\nProcess execution details:\n");
    displayProcessDetails(processes, n);

    return 0;
}
