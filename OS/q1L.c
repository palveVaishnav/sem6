#include <stdio.h>
#include <stdlib.h>

#define MAX_RESOURCES 10

// Structure to represent a process node
typedef struct Process {
    int id;
    int allocation[MAX_RESOURCES];
    int max_demand[MAX_RESOURCES];
    int need[MAX_RESOURCES];
    struct Process* next;
} Process;

// Function to create a new process node
Process* createProcess(int id, int alloc[], int max[]) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    for (int i = 0; i < MAX_RESOURCES; i++) {
        newProcess->allocation[i] = alloc[i];
        newProcess->max_demand[i] = max[i];
        newProcess->need[i] = max[i] - alloc[i];
    }
    newProcess->next = NULL;
    return newProcess;
}

// Function to check if the state is safe
int isSafe(Process* processes, int avail[], int n_resources) {
    int work[MAX_RESOURCES];
    int finish = 0;
    Process* current = processes;

    // Initialize work array
    for (int i = 0; i < n_resources; i++) {
        work[i] = avail[i];
    }

    // Iterate through all processes until all are finished or deadlock is detected
    while (finish == 0 && current != NULL) {
        int can_execute = 1;
        // Check if the current process can be executed
        for (int i = 0; i < n_resources; i++) {
            if (current->need[i] > work[i]) {
                can_execute = 0;
                break;
            }
        }
        // If the current process can be executed
        if (can_execute) {
            printf("Process %d can be executed.\n", current->id);
            // Update work array and finish flag
            for (int i = 0; i < n_resources; i++) {
                work[i] += current->allocation[i];
            }
            finish = 1;
        }
        current = current->next;
    }
    // If all processes are finished, the state is safe
    if (finish) {
        printf("The state is safe.\n");
        return 1;
    } else {
        // If deadlock is detected
        printf("Deadlock detected. The state is not safe.\n");
        return 0;
    }
}

int main() {
    int n_processes, n_resources;
    Process* processes = NULL;

    // Input number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n_processes);
    printf("Enter number of resources: ");
    scanf("%d", &n_resources);

    // Input allocation and max demand for each process
    for (int i = 0; i < n_processes; i++) {
        int alloc[MAX_RESOURCES], max[MAX_RESOURCES];
        printf("Enter allocation for Process %d: ", i);
        for (int j = 0; j < n_resources; j++) {
            scanf("%d", &alloc[j]);
        }
        printf("Enter max demand for Process %d: ", i);
        for (int j = 0; j < n_resources; j++) {
            scanf("%d", &max[j]);
        }
        // Create a new process node and append it to the linked list
        Process* newProcess = createProcess(i, alloc, max);
        if (processes == NULL) {
            processes = newProcess;
        } else {
            Process* temp = processes;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newProcess;
        }
    }

    // Input available resources
    int avail[MAX_RESOURCES];
    printf("Enter available resources: ");
    for (int i = 0; i < n_resources; i++) {
        scanf("%d", &avail[i]);
    }

    // Check if the state is safe
    isSafe(processes, avail, n_resources);

    // Free allocated memory for the linked list
    Process* temp;
    while (processes != NULL) {
        temp = processes;
        processes = processes->next;
        free(temp);
    }

    return 0;
}
