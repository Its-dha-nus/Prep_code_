#include <stdio.h>

// Step 1: Create a structure for a process as per the algorithm
struct Process {
    int pid;        // Process ID
    int bt;         // Burst Time
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
};

int main() {
    int n, i;
    float total_wt = 0, total_tat = 0;

    // Step 2: Accept the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Step 3: For each process, assign ID and accept Burst Time
    for (i = 0; i < n; i++) {
        p[i].pid = i;
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &p[i].bt);
    }

    // Step 4: Set waiting time of the first process as ‘0’ 
    // and turnaround time as its burst time.
    p[0].wt = 0;
    p[0].tat = p[0].bt;

    // Step 5: Calculate WT and TAT for the remaining processes
    for (i = 1; i < n; i++) {
        // (a) WT(n) = WT(n-1) + BT(n-1)
        p[i].wt = p[i-1].wt + p[i-1].bt;
        
        // (b) TAT(n) = WT(n) + BT(n)
        p[i].tat = p[i].wt + p[i].bt;
    }

    // Step 6: Calculate Totals and Averages
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    // (a) Average WT = Total WT / n
    // (b) Average TAT = Total TAT / n
    printf("\nAverage Waiting Time: %f", total_wt / n);
    printf("\nAverage Turnaround Time: %f\n", total_tat / n);

    return 0;
}