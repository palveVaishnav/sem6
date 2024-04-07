#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int n_processes;        
int n_resources;        

int alloc[MAX_PROCESSES][MAX_RESOURCES];  
int max[MAX_PROCESSES][MAX_RESOURCES];    
int avail[MAX_RESOURCES];                  
int need[MAX_PROCESSES][MAX_RESOURCES];   

int isSafe() {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES];
    int safe_sequence[MAX_PROCESSES];

    for (int i = 0; i < n_resources; i++) {
        work[i] = avail[i];
    }
    for (int i = 0; i < n_processes; i++) {
        finish[i] = 0;
    }

    int count = 0;
    while (count < n_processes) {
        int found = 0;
        for (int i = 0; i < n_processes; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < n_resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == n_resources) {
                    for (int k = 0; k < n_resources; k++) {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    safe_sequence[count++] = i;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("The state is not safe.\n");
            return 0;
        }
    }

    printf("The state is safe. Safe sequence is: ");
    for (int i = 0; i < n_processes; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");
    return 1;
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n_processes);
    printf("Enter number of resources: ");
    scanf("%d", &n_resources);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < n_resources; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter maximum demand matrix:\n");
    for (int i = 0; i < n_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < n_resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources vector: ");
    for (int i = 0; i < n_resources; i++) {
        scanf("%d", &avail[i]);
    }

    for (int i = 0; i < n_processes; i++) {
        for (int j = 0; j < n_resources; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    isSafe();

    return 0;
}
