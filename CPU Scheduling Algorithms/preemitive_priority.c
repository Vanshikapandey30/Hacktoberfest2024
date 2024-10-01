#include <stdio.h>

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
};

void calculateWaitingTurnaroundTime(struct Process processes[], int n) {
    int current_time = 0, completed = 0;
    int total_waiting_time = 0, total_turnaround_time = 0;

    while (completed != n) {
        int shortest = -1;
        int highest_priority = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 &&
                processes[i].priority < highest_priority) {
                shortest = i;
                highest_priority = processes[i].priority;
            }
        }

        if (shortest == -1) {
            current_time++;
        } else {
            if (processes[shortest].remaining_time == processes[shortest].burst_time) {
                processes[shortest].response_time = current_time - processes[shortest].arrival_time;
            }

            processes[shortest].remaining_time--;
            current_time++;

            if (processes[shortest].remaining_time == 0) {
                completed++;
                int finish_time = current_time;
                processes[shortest].turnaround_time = finish_time - processes[shortest].arrival_time;
                processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
                total_waiting_time += processes[shortest].waiting_time;
                total_turnaround_time += processes[shortest].turnaround_time;
            }
        }
    }

    printf("Process ID\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time,
               processes[i].response_time);
    }
    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].process_id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculateWaitingTurnaroundTime(processes, n);

    return 0;
}
