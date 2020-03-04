#include<stdio.h>
#include<stdlib.h>

void waitingTime(int processes[], int n, int bt[], int wt[]) {

	wt[0] = 0;

	for(int i=1; i<n; i++)
		wt[i] = bt[i-1] + wt[i-1];
}

void turnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {

	for(int i=0; i<n; i++)
		tat[i] = bt[i] + wt[i];
}

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void arrangeArrival(int n, int processes[], int bt[], int at[]) {
	for(int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++)
			if(at[j] > at[j]) {
				swap(&processes[j], &processes[j+1]);
				swap(&bt[j], &bt[j+1]);
				swap(&at[j], &at[j+1]);
			}
}

void SFJTime(int n, int processes[], int bt[], int at[], int wt[], int tat[]) {
	int temp, val, comp[n];
	comp[0] = at[0] + bt[0];
	tat[0] = comp[0] = at[0];
	wt[0] = tat[0] - bt[0];

	for(int i=1; i<n; i++) {
		temp = comp[i-1];
		int b_val = bt[i];
		for(int j=i; j<n; j++)
			if(temp>=at[j] && b_val >= bt[j]) {
				b_val = bt[j];
				val = j;
			}
		comp[val] = temp + bt[val];
		tat[val] = comp[val] - at[val];
		wt[val] = tat[val] - bt[val];

		swap(&processes[val], &processes[i]);
		swap(&comp[val], &comp[i]);
		swap(&bt[val], &bt[i]);
		swap(&wt[val], &wt[i]);
		swap(&at[val], &at[i]);
		swap(&tat[val], &tat[i]);
	}
}

void robinWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++) 
        rem_bt[i] =  bt[i];
	int t=0;
	while(1) {
		int done = 1;
		for(int i = 0; i<n; i++) {
			if(rem_bt[i] > 0) {
				done = 0;
				if(rem_bt[i] > quantum) {
					t += rem_bt[i];
					rem_bt[i] -= quantum;
				}
				else {
					t += rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if(done == 1)
			break;
	}
}

int main() {

	{
		int processes[] = {1, 2, 3, 4};
		int n = sizeof(processes)/sizeof(processes[0]);
		int arr_time[] = {2, 0, 4, 5};
		int burst_time[] = {3, 4, 2, 4};

		printf("Processes\tArrival Time\tBurst Time\n");
		for(int i=0; i<n; i++)
			printf("  %d\t\t%d\t\t%d\n", processes[i],arr_time[i] , burst_time[i]);

		printf("FCFS algo. implementation\n");

		//Waiting Time
		int wt[n];
		waitingTime(processes, n, burst_time, wt);

		//Turn Around Time
		int tat[n];
		turnAroundTime(processes, n, burst_time, wt, tat);

		printf("Processes\tBurst Time\tWaiting Time\tTurn Around Time\n");
		for(int i=0; i<n; i++)
			printf("  %d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i],arr_time[i] , burst_time[i], wt[i], tat[i]);
	}

	{
		int processes[] = {1, 2, 3, 4};
		int n = sizeof(processes)/sizeof(processes[0]);
		int arr_time[] = {2, 0, 4, 5};
		int burst_time[] = {3, 4, 2, 4};

		printf("Processes\tArrival Time\tBurst Time\n");
		for(int i=0; i<n; i++)
			printf("  %d\t\t%d\t\t%d\n", processes[i],arr_time[i] , burst_time[i]);

		printf("\nSFJ algo. implementation\n");

		//Arranging a/c to Arrival Time	
		arrangeArrival(n, processes, burst_time, arr_time);

		//Finalizing
		int wt[n], tat[n];
		SFJTime(n, processes, burst_time, arr_time, wt, tat);

		printf("Processes\tBurst Time\tWaiting Time\tTurn Around Time\n");
		for(int i=0; i<n; i++)
			printf("  %d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i],arr_time[i] , burst_time[i], wt[i], tat[i]);
	}
	{
		int processes[] = {1, 2, 3, 4};
		int n = sizeof(processes)/sizeof(processes[0]);
		int arr_time[] = {2, 0, 4, 5};
		int burst_time[] = {3, 4, 2, 4};

		printf("Processes\tArrival Time\tBurst Time\n");
		for(int i=0; i<n; i++)
			printf("  %d\t\t%d\t\t%d\n", processes[i],arr_time[i] , burst_time[i]);

		printf("\nRound Robin algo. implementation\n");
		int quantum = 2, wt[n], tat[n];

		//Waiting Time
		robinWaitingTime(processes, n, burst_time, wt, quantum);

		//Turn Around Time
		turnAroundTime(processes, n, burst_time, wt, tat);

		printf("Processes\tBurst Time\tWaiting Time\tTurn Around Time\n");
		for(int i=0; i<n; i++)
			printf("  %d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i],arr_time[i] , burst_time[i], wt[i], tat[i]);
	}

	return 0;
}
