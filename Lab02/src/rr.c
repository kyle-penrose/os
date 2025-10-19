#include <stdio.h>

// Function to perform Round Robin scheduling with different arrival times
void roundRobin(int processes[], int n, int burst_time[], int arrival_time[], int quantum) {
    int remaining_time[n], turnaround_time[n], response_time[n];
    int total_tat = 0, total_rt = 0;
    int time = 0, completed = 0;
    int first_response[n];

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
        first_response[i] = -1; // -1 means process hasn't started yet
    }

    // Continue until all processes are completed
    while (completed < n) {
        int all_waiting = 1; // check if all processes are waiting

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && arrival_time[i] <= time)
            {
                all_waiting = 0; // at least one process is ready to execute

                if (first_response[i] == -1) {
                    first_response[i] = time; // set response time
                }

                // execute process for quantum or remaining time
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    turnaround_time[i] = time - arrival_time[i];
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }

        // if all process are waiting (not arrived yet), advance time
        if (all_waiting) {
            time++;
        }
    }

    // Print process details
    printf("Process\tBurst Time\tArrival Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = turnaround_time[i];
        response_time[i] = first_response[i] - arrival_time[i];
        total_tat += turnaround_time[i];
        total_rt += response_time[i];

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], arrival_time[i], turnaround_time[i], response_time[i]);
    }

    // print average times
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
    printf("Average response time = %.2f\n", (float)total_rt / n);
}

int main(){
    int processes[] = {1, 2, 3}; // process IDs
    int burst_time[] = {40, 20, 10}; // Burst time for each process
    int arrival_time[] = {0, 0, 5}; // Arrival times for each process
    int n = sizeof(processes) / sizeof(processes[0]); // Number of processes
    int quantum = 5; // Time quantum

    // Call Round Robin scheduling function
    roundRobin(processes, n, burst_time, arrival_time, quantum);

    return 0;
}
