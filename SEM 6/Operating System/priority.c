#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int arrival_time;
    int cpu_burst;
    int priority;
    int remaining_burst;
    struct Process *next;
} Process;

// Function to create a new process
Process* createProcess(int id, int arrival_time, int cpu_burst, int priority) {
    Process *newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->arrival_time = arrival_time;
    newProcess->cpu_burst = cpu_burst;
    newProcess->priority = priority;
    newProcess->remaining_burst = cpu_burst;
    newProcess->next = NULL;
    return newProcess;
}

// Function to insert a process into the ready queue based on priority
void insertProcess(Process **ready_queue, Process *newProcess) {
    if (*ready_queue == NULL || (*ready_queue)->priority > newProcess->priority) {
        newProcess->next = *ready_queue;
        *ready_queue = newProcess;
    } else {
        Process *temp = *ready_queue;
        while (temp->next != NULL && temp->next->priority <= newProcess->priority) {
            temp = temp->next;
        }
        newProcess->next = temp->next;
        temp->next = newProcess;
    }
}

// Function to simulate preemptive priority scheduling
void preemptivePriorityScheduling(Process *processes, int n) {
    int current_time = 0;
    Process *ready_queue = NULL;
    Process *current_process = NULL;

    while (1) {
    // Check if there are any processes arriving at the current time
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time == current_time) {
            insertProcess(&ready_queue, &processes[i]);
        }
    }

    // If no process is currently running and ready queue is not empty, select a process to run
    if (current_process == NULL && ready_queue != NULL) {
        current_process = ready_queue;
        ready_queue = ready_queue->next;
    }

    // If a process is running, decrease its remaining burst time and check for preemption
    if (current_process != NULL) {
        printf("| P%d ", current_process->id);
        current_process->remaining_burst--;

        // Check if the current process needs to be preempted
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_burst < current_process->remaining_burst && processes[i].priority < current_process->priority) {
                printf("(%d) ", current_time);
                current_process = &processes[i];
                break;
            }
        }

        // If the current process has completed its burst, calculate turnaround time and select next process
        if (current_process->remaining_burst == 0) {
            printf("(%d) ", current_time + 1);
            current_process = NULL;
        }
    } else {
        printf("| IDLE ");
    }

    current_time++;

    // Check if all processes have completed execution
    int all_processes_completed = 1;
    for (int i = 0; i < n; i++) {
        if (processes[i].remaining_burst > 0 || processes[i].arrival_time > current_time) {
            all_processes_completed = 0;
            break;
        }
    }

    if (all_processes_completed && ready_queue == NULL && current_process == NULL) {
        break;
    }
}



    printf("|\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process*)malloc(n * sizeof(Process));

    printf("Enter arrival time, CPU burst, and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        int arrival_time, cpu_burst, priority;
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &arrival_time, &cpu_burst, &priority);
        processes[i] = *createProcess(i + 1, arrival_time, cpu_burst, priority);
    }

    printf("Gantt Chart:\n");
    preemptivePriorityScheduling(processes, n);

    free(processes);

    return 0;
}
