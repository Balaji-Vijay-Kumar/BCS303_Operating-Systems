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
    
    // Calculate completion time, turnaround time, and waiting time for each process
    completion_time[0] = burst_time[0];
    turnaround_time[0] = completion_time[0] - arrival_time[0];
    waiting_time[0] = turnaround_time[0] - burst_time[0];
    
    // Loop to calculate completion time, turnaround time, and waiting time for subsequent processes
    for (i = 1; i < num_processes; ++i) {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }
    
    // Calculate sum of turnaround time and sum of waiting time for all processes
    float sum_TAT = 0, sum_WT = 0; // Variables to store the sum of TAT and WT
    
    for (i = 0; i < num_processes; ++i) {
        sum_TAT = sum_TAT + turnaround_time[i]; // Calculating the sum of turnaround times
        sum_WT = sum_WT + waiting_time[i]; // Calculating the sum of waiting times
    }
    
    // Calculate the averages
    avg_TAT = sum_TAT / num_processes; // Calculating the average turnaround time
    avg_WT = sum_WT / num_processes; // Calculating the average waiting time
    
    // Display the table header for process data
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    
    // Display the process details in a tabular format
    for (i = 0; i < num_processes; ++i) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    
    // Display average turnaround time and average waiting time
    printf("\nAverage Turnaround Time: %.2f", avg_TAT);
    printf("\nAverage Waiting Time: %.2f\n", avg_WT);
    
    return 0;
}

/* Sample Input to the program:

Enter the number of processes: 5
Enter Arrival Time for Process 1: 0
Enter Burst Time for Process 1: 4
Enter Arrival Time for Process 2: 1
Enter Burst Time for Process 2: 3
Enter Arrival Time for Process 3: 2
Enter Burst Time for Process 3: 1
Enter Arrival Time for Process 4: 3
Enter Burst Time for Process 4: 2
Enter Arrival Time for Process 5: 4
Enter Burst Time for Process 5: 5

*/
