#include <stdio.h>

/*
   #######################################################################################################
   #                                                                                                     #
   #   This program is contributed by Balaji V, Assistant Professor,                                     #
   #   Department of Computer Science & Engineering - AI & ML,                                           #
   #   The National Institute of Engineering, Mysuru.                                                    #
   #                                                                                                     #
   #######################################################################################################
*/

int main() {
    // Declare variables
    int num_processes, i;
    float avg_TAT = 0, avg_WT = 0;

    // Prompt user to enter the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes); // Taking input for the number of processes

    // Arrays to store arrival time, burst time, completion time, turnaround time, and waiting time for each process
    int arrival_time[num_processes], burst_time[num_processes], completion_time[num_processes];
    int turnaround_time[num_processes], waiting_time[num_processes];
    int original_burst_time[num_processes]; // Array to preserve original burst times

    // Input arrival time and burst time for each process
    for (i = 0; i < num_processes; ++i) {
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);

        // Store original burst time values
        original_burst_time[i] = burst_time[i];
    }

    // Initialize the variables for scheduling
    int current_time = 0; // Current time initialized to 0

    // Calculate completion time, turnaround time, and waiting time for each process
    for (i = 0; i < num_processes; ++i) {
        // Find the shortest job arriving until the current time
        int shortest_job_index = -1;
        int shortest_burst = 999999; // Set a high value initially

        for (int j = 0; j < num_processes; ++j) {
            if (arrival_time[j] <= current_time && burst_time[j] < shortest_burst && burst_time[j] > 0) {
                shortest_burst = burst_time[j];
                shortest_job_index = j;
            }
        }

        if (shortest_job_index == -1) {
            // No job available to execute, find the next job arrival time
            int next_arrival = 999999; // Set a high value initially

            for (int k = 0; k < num_processes; ++k) {
                if (arrival_time[k] > current_time && arrival_time[k] < next_arrival) {
                    next_arrival = arrival_time[k];
                }
            }

            current_time = next_arrival; // Move current time to the next arrival time
            i--; // To recheck the jobs available at this new time
        } else {
            // If arrival time is greater than the current time, CPU is idle
            if (arrival_time[shortest_job_index] > current_time) {
                current_time = arrival_time[shortest_job_index]; // Move current time to the arrival time of the next process
                i--; // To recheck the jobs available at this new time
            } else {
                // Calculate completion time, turnaround time, and waiting time
                completion_time[shortest_job_index] = current_time + burst_time[shortest_job_index];
                turnaround_time[shortest_job_index] = completion_time[shortest_job_index] - arrival_time[shortest_job_index];
                waiting_time[shortest_job_index] = turnaround_time[shortest_job_index] - original_burst_time[shortest_job_index];

                // Update current time to completion time for the next iteration
                current_time = completion_time[shortest_job_index];

                // Set burst time to a very high value for the processed job to mark it as completed
                burst_time[shortest_job_index] = 999999;
            }
        }
    }

    // Calculate average turnaround time and average waiting time
    for (i = 0; i < num_processes; ++i) {
        avg_TAT += turnaround_time[i];
        avg_WT += waiting_time[i];
    }

    // Calculate the averages
    avg_TAT /= num_processes;
    avg_WT /= num_processes;

    // Display the table header for process data
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    // Display the process details in the order they were entered by the user
    for (i = 0; i < num_processes; ++i) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], original_burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    // Display average turnaround time and average waiting time
    printf("\nAverage Turnaround Time: %.2f", avg_TAT);
    printf("\nAverage Waiting Time: %.2f\n", avg_WT);

    return 0;
}

/* Sample Input:
Enter the number of processes: 5
Enter Arrival Time for Process 1: 1
Enter Burst Time for Process 1: 7
Enter Arrival Time for Process 2: 2
Enter Burst Time for Process 2: 5
Enter Arrival Time for Process 3: 3
Enter Burst Time for Process 3: 1
Enter Arrival Time for Process 4: 4
Enter Burst Time for Process 4: 2
Enter Arrival Time for Process 5: 5
Enter Burst Time for Process 5: 8
*/
