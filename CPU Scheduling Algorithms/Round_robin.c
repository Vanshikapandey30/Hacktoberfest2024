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

void calculateTimes(struct Process processes[], int n, int quantum) {
    int remaining_processes = n;
    int current_time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival_time <= current_time) {
                if (processes[i].response_time == -1) {
                    processes[i].response_time = current_time - processes[i].arrival_time;
                }

                if (processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    processes[i].completed = 1;
                    remaining_processes--;
                }
            }
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
    int n, quantum;

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

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    calculateTimes(processes, n, quantum);

    printf("\nProcess execution details:\n");
    displayProcessDetails(processes, n);

    return 0;
}
