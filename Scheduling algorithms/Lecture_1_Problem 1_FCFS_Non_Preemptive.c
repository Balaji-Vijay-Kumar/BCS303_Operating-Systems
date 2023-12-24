#include <stdio.h>

// Function to calculate completion time, turnaround time, waiting time, and display the results
void calculateTimes(int processes[], int n, int burst_time[], int arrival_time[]) {
    int completion_time[n], turnaround_time[n], wait_time[n];

    // Initializing completion_time[0] and wait_time[0] for the first process
    completion_time[0] = burst_time[0];
    wait_time[0] = 0;

    // Calculating completion time, turnaround time, and waiting time for each process
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + burst_time[i]; // Calculating completion time
        turnaround_time[i] = completion_time[i] - arrival_time[i];    // Calculating turnaround time
        wait_time[i] = turnaround_time[i] - burst_time[i];            // Calculating waiting time
    }

    // Printing header for the table
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    float total_wait_time = 0, total_turnaround_time = 0;
    // Printing process details and accumulating total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        // Correcting Turnaround Time for the first process as it should be equal to completion time
        if (i == 0) {
            turnaround_time[i] = completion_time[i];
        }
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], wait_time[i]);
        total_wait_time += wait_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Calculating and displaying average waiting time and average turnaround time
    float avg_wait_time = total_wait_time / n;
    float avg_turnaround_time = total_turnaround_time / n;
    printf("\nAverage waiting time = %.2f\n", avg_wait_time);
    printf("Average turnaround time = %.2f\n", avg_turnaround_time);
}

// Main function
int main() {
    // Process details
    int processes[] = {1, 2, 3, 4, 5}; // Process IDs
    int n = sizeof processes / sizeof processes[0]; // Number of processes
int arrival_time[] = {0, 1, 2, 3, 4}; // Arrival times of processes    
int burst_time[] = {4, 3, 1, 2, 5}; // Burst times of processes
    

    // Calling the calculateTimes function to calculate and display process times
    calculateTimes(processes, n, burst_time, arrival_time);

    return 0;
}


