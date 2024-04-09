#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50

// Structure for file directory entry
struct direct_entry {
    char filename[MAX_FILENAME_LENGTH];
    int start_block;
    int length;
    struct direct_entry *next;
};

// Global variables for directory
struct direct_entry *head = NULL;
struct direct_entry *cur = NULL;
int *bitVector = NULL;

// Function prototypes
void initializeBitVector(int diskSize);
void showBitVector(int diskSize);
void createNewFile(int diskSize);
void showDirectory();
void deleteFile();
void clearInputBuffer();

int main() {
    int choice;
    int diskSize;

    printf("Enter disk size: ");
    scanf("%d", &diskSize);

    // Initialize bit vector
    initializeBitVector(diskSize);

    do {
        printf("\nMenu:\n");
        printf("1. Show bit vector\n");
        printf("2. Create new file\n");
        printf("3. Show Directory\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showBitVector(diskSize);
                break;
            case 2:
                createNewFile(diskSize);
                break;
            case 3:
                showDirectory();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    free(bitVector); // Free allocated memory for bit vector
    return 0;
}

void initializeBitVector(int diskSize) {
    bitVector = (int *)malloc(diskSize * sizeof(int));
    if (bitVector == NULL) {
        printf("Memory allocation failed for bit vector!\n");
        exit(1);
    }

    // srand(time(NULL));
    // for (int i = 0; i < diskSize; ++i) {
    //     bitVector[i] = rand() % 2; // Randomly initialize bit vector
    // }
    for (int i = 0; i < diskSize; ++i) {
        bitVector[i] = 0; // all free space initially
    }
}

void showBitVector(int diskSize) {
    printf("Bit vector of disk blocks:\n");
    for (int i = 0; i < diskSize; ++i) {
        printf("Block %d: %s\n", i, bitVector[i] ? "Allocated" : "Free");
    }
}

void createNewFile(int diskSize) {
    struct direct_entry *newFile = (struct direct_entry *)malloc(sizeof(struct direct_entry));
    if (newFile == NULL) {
        printf("Memory allocation failed for new file!\n");
        return;
    }

    printf("Enter file name: ");
    clearInputBuffer();
    fgets(newFile->filename, MAX_FILENAME_LENGTH, stdin);
    newFile->filename[strcspn(newFile->filename, "\n")] = '\0'; // Remove newline character

    printf("Enter number of blocks to allocate for the file: ");
    scanf("%d", &newFile->length);

    // Find consecutive free blocks for file allocation
    int consecutiveBlocks = 0;
    int startBlock = -1;
    for (int i = 0; i < diskSize; ++i) {
        if (bitVector[i] == 0) {
            if (consecutiveBlocks == 0) {
                startBlock = i;
            }
            consecutiveBlocks++;
            if (consecutiveBlocks == newFile->length) {
                break;
            }
        } else {
            consecutiveBlocks = 0;
            startBlock = -1;
        }
    }

    if (consecutiveBlocks != newFile->length) {
        printf("Not enough consecutive free blocks available for file allocation.\n");
        free(newFile);
        return;
    }

    // Mark blocks as allocated in bit vector
    for (int i = startBlock; i < startBlock + newFile->length; ++i) {
        bitVector[i] = 1;
    }

    newFile->start_block = startBlock;
    newFile->next = NULL;

    if (head == NULL) {
        head = newFile;
        cur = newFile;
    } else {
        cur->next = newFile;
        cur = newFile;
    }

    printf("File '%s' created successfully!\n", newFile->filename);
}

void showDirectory() {
    if (head == NULL) {
        printf("Directory is empty.\n");
        return;
    }

    printf("Directory:\n");
    struct direct_entry *current = head;
    while (current != NULL) {
        printf("File Name: %s, Start Block: %d, Length: %d\n", current->filename, current->start_block, current->length);
        current = current->next;
    }
}

void deleteFile() {
    if (head == NULL) {
        printf("Directory is empty. No file to delete.\n");
        return;
    }

    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the file to delete: ");
    clearInputBuffer();
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

    struct direct_entry *prev = NULL;
    struct direct_entry *current = head;

    while (current != NULL) {
        if (strcmp(current->filename, filename) == 0) {
            // Mark blocks as free in bit vector
            for (int i = current->start_block; i < current->start_block + current->length; ++i) {
                bitVector[i] = 0;
            }

            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("File '%s' deleted successfully!\n", filename);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("File '%s' not found.\n", filename);
}

void clearInputBuffer() {
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
