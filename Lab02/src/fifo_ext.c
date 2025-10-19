#include <stdio.h>
#include <stdlib.h>
#define NUM_PROC 3

struct process {int id, arrival_time, burst_time, turnaround_time, response_time; };

// Comparison function for qsort
int compareProc(const void* a, const void* b)
{
    return ((struct process*)a)->arrival_time - ((struct process*)b)->arrival_time;
}

// Function to calculate turnaround time and response time using FIFO scheduling
void fifo(struct process processes[], int n) {

    int total_tat = 0, total_rt = 0;  // Variables for total turnaround and response times
    
    // Sort the processes in order of arrival time
    qsort(processes, n, sizeof(struct process), compareProc);

    // First process starts immediately
    processes[0].response_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    // Add first process times to totals
    total_tat += processes[0].turnaround_time;
    total_rt += processes[0].response_time;

    // Calculate response and turnaround times for remaining processes
    for (int i = 1; i < n; i++) {
        processes[i].response_time = processes[i - 1].response_time + processes[i - 1].burst_time; // Response time is the sum of previous burst times
        processes[i].turnaround_time = processes[i].response_time + processes[i].burst_time; // Turnaround time = response time + burst time

        total_tat += processes[i].turnaround_time; // Accumulate total turnaround time
        total_rt += processes[i].response_time;  // Accumulate total response time
    }

    // Display process details
    printf("Process\tArrival Time\tBurst Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%8d\t%8d\t%8d\t%8d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].turnaround_time, processes[i].response_time);

    //Print average times
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
    printf("Average response time = %.2f\n", (float)total_rt / n);
}

int main() {
 
    struct process processes[NUM_PROC]; // Array of Procs
  
    // initialize process data
    processes[0].id = 1;
    processes[0].arrival_time = 3;
    processes[0].burst_time = 10;
    
    processes[1].id = 2;
    processes[1].arrival_time = 0;
    processes[1].burst_time = 5;

    processes[2].id = 3;
    processes[2].arrival_time = 6;
    processes[2].burst_time = 8;

    fifo(processes, NUM_PROC); // Call the FIFO function

    return 0;
}

