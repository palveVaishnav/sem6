#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fcfs{
	int p, bt;
	float at, st, ct, tat, wt;
	struct fcfs *next;
} *head = NULL;

void main(){
	struct fcfs *new, *current;
	float arr_time;
	int i, id, n, burst_time;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		new = (struct fcfs *)malloc(sizeof(struct fcfs));
		printf("\nEnter the process ID:  ");
		scanf("%d", &id);
		new->p = id;
		printf("\nEnter the Arrival time: ");
		scanf("%f", &arr_time);
		new->at = arr_time;

		printf("\nEnter the Burst time: ");
		scanf("%d", &burst_time);
		new->bt = burst_time;
		new->next = NULL;

		if (head == NULL){
			head = current = new;
		}
		else{
			current = head;
			while (current->next != NULL){
				current = current->next;
			}
			current->next = new;
		}
	}

	printf("\nBefore sorting the process \n");
	printf("\nProcess ID\t\t\t Arrival time\t\t\tBurst time");
	current = head;
	while (current != NULL){
		printf("\n%d\t\t\t\t%f\t\t\t\t%d\t\t\t\t", current->p, current->at, current->bt);
		current = current->next;
	}

	int swapped, tmp;
	float tmp1;
	struct fcfs *ptr1;
	struct fcfs *lptr = NULL;
	if (head == NULL)
		return;
	do{
		swapped = 0;
		ptr1 = head;
		while (ptr1->next != NULL){
			if (ptr1->at > ptr1->next->at){
				tmp1 = ptr1->at;
				ptr1->at = ptr1->next->at;
				ptr1->next->at = tmp1;

				tmp = ptr1->bt;
				ptr1->bt = ptr1->next->bt;
				ptr1->next->bt = tmp;

				tmp = ptr1->p;
				ptr1->p = ptr1->next->p;
				ptr1->next->p = tmp;

				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
	} while (swapped);

	printf("\nAfter sorting the processes\n");
	printf("\nProcess ID\t\t\t Arrival time\t\t\tBurst time");
	current = head;
	while (current != NULL){
		printf("\n%d\t\t\t\t%f\t\t\t\t%d\t\t\t\t", current->p, current->at, current->bt);
		current = current->next;
	}
	// Finding idle time

	float k = 0;
	current = head;
	float idle[50], gnt[50];
	tmp = 0;
	for (i = 0; i < n; i++){
		if (current->at > k)
		{
			idle[i] = current->at - k;
		}
		else
			idle[i] = 0;
		gnt[i] = current->bt;
		k = idle[i] + current->bt + k;
		current = current->next;
	}

	printf("\n*******************Gantt Chart**************************\n|");
	current = head;
	k = 0;
	printf("\nStart time\t\t\tprocess Id\t\t\tFinish time\n");
	for (i = 0; i < n; i++)
	{
		if (idle[i] > 0)
		{
			printf("%f\t\t\tIDLE time\t\t\t\%f\n", k, k + idle[i]);
			k = k + idle[i];
		}
		printf("%f\t\t\t\t", k);
		k = k + gnt[i];
		current->ct = k;
		current->tat = current->ct - current->at;
		current->wt = current->tat - current->bt;

		printf("p%d\t\t\t%f\n", current->p, k);
		current = current->next;
	}

	printf("\n\n\n******************Process Details******************\n");
	printf("\nProcess\t\tArrival time\t\tBurst time\t\tcompletion time\t\t TAT\t\tWaiting time\t\n");

	current = head;
	float total_wt = 0, total_tat = 0;
	while (current)
	{
		printf("%d\t\t%f\t\t%d\t\t\t%f\t\t\t%f\t\t%f\n", current->p, current->at, current->bt, current->ct, current->tat, current->wt);
		total_wt = total_wt + current->wt;
		total_tat = total_tat + current->tat;
		current = current->next;
	}
	printf("\nAverage turnaround time: %f \n Average waiting time : %f\n", total_tat / n, total_wt / n);
}
