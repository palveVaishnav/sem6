// priority Scheduling 

#include<stdio.h>
#include<stdlib.h>

int n=0;

typedef struct Process{
    int id;
    int burstTime;
    int priority;
    struct Process* next;
}Process;

Process* createNode(int id,int burstTIme,int priority){
    Process* newNode = (Process*)malloc(sizeof(Process));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->id = id;
    newNode->burstTime = burstTIme;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Process** head, Process* newNode){
    if(*head == NULL || (*head)->priority > newNode->priority ){
        printf("------Here- If------");
        newNode->next = *head;
        *head = newNode;
    }else{
        printf("------Here-- Else -----");
        Process* curr = *head;
        while(curr->next != NULL && curr->next->priority < newNode->priority){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}


void priorityScheduling(Process* head){
    int totalWt=0;
    int totalTat=0;
    printf("\nProcess Id\tPriority \tBurst Time \tTurnaround Time \tWaiting time");
    
    Process* current = head;
    while(current != NULL){
        totalTat+=current->burstTime;
        printf("\n%d\t\t%d\\t%d\t\t%d\t\t%d",current->id,current->priority,current->burstTime,totalTat,totalWt);
        totalWt +=  current->burstTime;
        current = current->next;
    }

    printf("\nAvg turnAround Time : %.2f",(float)totalTat/n);
    printf("\nAvg Waiting Time : %.2f",(float)totalWt/n);

    return;
}




int main(){
    printf("\nEnter thhe number of Processes : ");
    scanf("%d",&n);
    struct Process* head = NULL;
    int  id=0;
    int burstTime = -1;
    int prioirty = -1;
    for(int i=0;i<n;i++){
        do{
            printf("\nEnter the burst time for %d process: ",i+1);
            scanf("%d",&burstTime);
        }while(burstTime<0);
        do{
            printf("\nEnter the prioirty : ");
            scanf("%d",&prioirty);
        }while(prioirty<0);

        insertNode(&head,createNode(id++,burstTime,prioirty));
    }

    Process* print = head;
    while(print != NULL){
        printf("id :%d, priority: %d, burst: %d\n",print->id,print->priority,print->burstTime);
        print = print->next;
    }

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