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

    // Input arrival time and burst time for each process
    for (i = 0; i < num_processes; ++i) {
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Sort the processes based on their arrival time in ascending order using bubble sort algorithm
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                // Swap arrival times
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;

                // Swap burst times
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
            }
        }
    }

    // Initialize the variables for scheduling
    int current_time = 0; // Current time initialized to 0
    int total_idle_time = 0; // Total idle time initialized to 0

    // If arrival time of the first process is not 0, calculate idle time until the first process arrives
    if (arrival_time[0] != 0) {
        total_idle_time = arrival_time[0]; // Total idle time is the arrival time of the first process
        current_time = arrival_time[0]; // Move current time to the arrival time of the first process
    }

    // Calculate completion time, turnaround time, and waiting time for each process
    for (i = 0; i < num_processes; ++i) {
        // If arrival time is greater than current time, CPU is idle
        if (arrival_time[i] > current_time) {
            total_idle_time += arrival_time[i] - current_time; // Calculate total idle time
            current_time = arrival_time[i]; // Move current time to the arrival time of the next process
        }

        // Calculate completion time, turnaround time, and waiting time
        completion_time[i] = current_time + burst_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];

        // Update current time to completion time for the next iteration
        current_time = completion_time[i];
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

    // Display the process details in a tabular format
    for (i = 0; i < num_processes; ++i) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    // Display average turnaround time, average waiting time, and total idle time
    printf("\nAverage Turnaround Time: %.2f", avg_TAT);
    printf("\nAverage Waiting Time: %.2f", avg_WT);
    printf("\nTotal Idle Time: %d\n", total_idle_time);

    return 0;
}


/*Sample Input to be given to the program:

Enter the number of processes: 5
Enter Arrival Time for Process 1: 2
Enter Burst Time for Process 1: 6
Enter Arrival Time for Process 2: 3
Enter Burst Time for Process 2: 3
Enter Arrival Time for Process 3: 5
Enter Burst Time for Process 3: 7
Enter Arrival Time for Process 4: 6
Enter Burst Time for Process 4: 4
Enter Arrival Time for Process 5: 8
Enter Burst Time for Process 5: 5

*/
