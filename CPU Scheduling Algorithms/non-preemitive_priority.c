#include <stdio.h>

struct Process {
    int pid; 
    int burst_time; 
    int arrival_time; 
    int priority; 
    int waiting_time; 
    int turnaround_time; 
    int response_time; 
    int completed; 
};

void calculateTimes(struct Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    int min_priority, next_process;

    while (completed_processes < n) {
        min_priority = 9999; 
        next_process = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !processes[i].completed) {
                if (processes[i].priority < min_priority) {
                    min_priority = processes[i].priority;
                    next_process = i;
                }
            }
        }

        if (next_process == -1) {
            current_time++;
            continue;
        }

        processes[next_process].response_time = current_time - processes[next_process].arrival_time;
        processes[next_process].waiting_time = current_time - processes[next_process].arrival_time;
        processes[next_process].turnaround_time = processes[next_process].waiting_time + processes[next_process].burst_time;

        current_time += processes[next_process].burst_time;
        processes[next_process].completed = 1;
        completed_processes++;
    }
}

void displayProcessDetails(struct Process processes[], int n) {
    printf("PID\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\tResponse Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time,
               processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].response_time = -1; 
        processes[i].completed = 0;
    }

    calculateTimes(processes, n);

    printf("\nProcess execution details:\n");
    displayProcessDetails(processes, n);

    return 0;
}
