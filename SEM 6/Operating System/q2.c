#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int id;
    int burst_time;
    int priority;
    struct Process* next;
} Process;

// Function to create a new process node
Process* createProcess(int id, int burst_time, int priority) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->burst_time = burst_time;
    newProcess->priority = priority;
    newProcess->next = NULL;
    return newProcess;
}

// Function to insert a process node into the linked list
void insertProcess(Process** head, Process* newProcess) {
    if (*head == NULL || (*head)->priority > newProcess->priority) {
        newProcess->next = *head;
        *head = newProcess;
    } else {
        Process* current = *head;
        while (current->next != NULL && current->next->priority <= newProcess->priority) {
            current = current->next;
        }
        newProcess->next = current->next;
        current->next = newProcess;
    }
}

// Function to simulate priority scheduling
void priorityScheduling(Process* head) {
    int waiting_time = 0;
    int turnaround_time = 0;
    int process_count = 0;

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    Process* current = head;
    while (current != NULL) {
        printf("%d\t%d\t\t%d\t\t%d\t\t", current->id, current->burst_time, current->priority, waiting_time);
        turnaround_time += current->burst_time;
        printf("%d\n", turnaround_time);
        waiting_time += current->burst_time;
        process_count++;
        current = current->next;
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)turnaround_time / process_count);
    printf("Average Waiting Time: %.2f\n", (float)waiting_time / process_count);
}

int main() {
    int n;
    Process* head = NULL;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process and insert into linked list
    for (int i = 0; i < n; i++) {
        int burst_time, priority;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &priority);
        Process* newProcess = createProcess(i + 1, burst_time, priority);
        insertProcess(&head, newProcess);
    }

    Process* print = head;
    while(print != NULL){
        printf("id :%d, priority: %d, burst: %d\n",print->id,print->priority,print->burst_time);
        print = print->next;
    }

    

    // Simulate priority scheduling
    priorityScheduling(head);

    // Free allocated memory for the linked list
    Process* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
