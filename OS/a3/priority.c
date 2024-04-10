#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n=-1;

struct process{
	int id;
	int at;
	int bt;
	int priority;
	int remainingTime;
	struct process* next;
};
struct process* head = NULL;


struct priorityQ{
	int id;
	int at;
	int bt;
	int p;
	int rtime;
	struct priorityQ* next;
};
struct priorityQ* phead = NULL;

void printAll(){
	struct process* temp = head;
	printf("\n------------ All Processes ----------------");
	while(temp != NULL){
		printf("\nid : %d",temp->id);
		printf("\nAT : %d",temp->at);
		printf("\nBT : %d",temp->bt);
		printf("\nPriority : %d",temp->priority);
		printf("\nRemaining Time : %d",temp->remainingTime);
		temp = temp->next;
		printf("\n-----------------------");
	}
	return;
}


void addProcess(int id,int at,int bt,int p){
	struct process* newNode = (struct process*)malloc(sizeof(struct process));
	if(newNode == NULL){
		printf("Node Eror");
	}
	newNode->id = id;
	newNode->at = at;
	newNode->bt = bt;
	newNode->priority = p;
	newNode->remainingTime = bt;
	newNode->next = NULL;

	// add the node to list 
	if(head == NULL){
		head = newNode;
	}else{
		struct process* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}//added
}



void swap(struct process* a,struct process* b){
	// id,at,bt,priority,remainingtime
	int id = a->id;
	a->id = b->id;
	b->id = id;

	int at = a->at;
	a->at = b->at;
	b->at = at;

	int bt = a->bt;
	a->bt = b->bt;
	b->bt = bt;

	int priority = a->priority;
	a->priority = b->priority;
	b->priority = priority;

	int rt = a->remainingTime;
	a->remainingTime = b->remainingTime;
	b->remainingTime = rt;
	
	return;
}
	


void sortArrivalTime(){
	int changed;
	do{
		changed=0;
		struct process* temp = head;
		while(temp->next != NULL){
			if(temp->at > temp->next->at){
				swap(temp,temp->next);
				changed = 1;
			}
			temp = temp->next;
		}
	}while(changed);
}//sort



void addPriority(struct process * p){
	struct priorityQ* newNode = (struct priorityQ *)malloc(sizeof(struct priorityQ));
	newNode->id = p->id;
	newNode->at = p->at;
	newNode->bt = p->bt;
	newNode->p = p->priority;
	newNode->rtime = p->remainingTime;

	if(phead == NULL){
		phead = newNode;
		phead->next = NULL;
	}else if(newNode->p < phead->p){
		newNode->next = phead;
		phead = newNode;
	}else if(phead->next == NULL){
		newNode->next = NULL;
		phead->next = newNode;
	}else{
		struct priorityQ* temp = phead;		
		while(temp->next->p < newNode->p && temp->next != NULL){
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return;
}




void printAllP(){
	struct priorityQ* temp = phead;
	printf("\n------------ All Processes ----------------");
	while(temp != NULL){
		printf("\nid : %d",temp->id);
		printf("\nAT : %d",temp->at);
		printf("\nBT : %d",temp->bt);
		printf("\nPriority : %d",temp->p);
		printf("\nRemaining Time : %d",temp->rtime);
		temp = temp->next;
		printf("\n-----------------------");
	}
	return;
}



void priorityAlgorithm(){
	int cputime = 0 ;
	int complete = 0 ;

	struct process* track = head;
	while(complete != n){
		printf("\nCompleted : %d ",complete);
		printf("\nCPU time : %d",cputime);
		if(track != NULL){		
			if(cputime == track->at){
			//track = track->next;
				addPriority(track);
				track = track->next;
			}
		}
		if(phead != NULL){
			phead->rtime -= 1;
			if(phead->rtime == 0){
				complete++;
				phead = phead->next;
			}
		}else{
			printf("\nCPU IDLE");
		}
		cputime++;
		//printAllP();
	}
	return;
}



int main(){
	
	do{
		printf("Enter The number of processes ( > 0 ) : ");
		scanf("%d",&n);
	}while( n < 1);
	
	int at = -1,bt=-1,p=-1;
	printf("Enter process Details : \n-----------------------------");
	for(int i=0;i<n;i++){
		printf("\nFor Process id : %d ",i);
		do{
			printf("\nEnter Arrival time ( >= 0 ) : ");
			scanf("%d",&at);
		}while(at < 0);
		do{
			printf("Enter Burst Time ( > 0 ) : ");
			scanf("%d",&bt);
		}while(bt < 1);
		do{
			printf("Enter Priority ( > 0 ) : ");
			scanf("%d",&p);
		}while(p < 1);
		addProcess(i,at,bt,p);
		printf("-------------------------");

	
	}
	//printAll();
	sortArrivalTime();
	printAll();
	priorityAlgorithm();
	printAllP();
	return 0;

}











