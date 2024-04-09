// non premptive sjf

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
struct process{
	int id;
	int AT;
	int BT;
	struct process* next;
};
struct process* head = NULL;


struct gantt{
	int id;
	int st;
	int ft;
	int tat;
	int wt;
	struct gantt* next;
};

struct gantt* ghead = NULL;

void addProcess(int id,int at,int bt){
	
	struct process* newNode = (struct process*)malloc(sizeof(struct process));
	if(newNode == NULL){
		printf("Node Error");
		return;
	}
	newNode->id = id;
	newNode->AT = at;
	newNode->BT = bt;
	newNode->next = NULL;

	if(head ==NULL){
		head = newNode;
	}else{
		struct process *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	printf("\nProcess Added ....");
	return;

}

void printAll(){
	struct process* temp = head;
	printf("\nProcess id\tArrival Time\tBurst Time");
	while(temp != NULL){
		printf("\n%d\t\t",temp->id);
		printf("%d\t\t",temp->AT);
		printf("%d",temp->BT);
		temp = temp->next;
	}
	return;
}


void swap(struct process* a, struct process*b){
	int id = a->id;
	a->id = b->id;
	b->id = id;

	int at = a->AT;
	a->AT = b->AT;
	b->AT = at;

	int bt = a->BT;
	a->BT = b->BT;
	b->BT = bt;
	return;
}


void sjfAlgorithm(){
	// sort according to the burst time
	int listChanged;
	do{
		listChanged = 0;
		struct process* temp = head;
		while(temp->next != NULL){
			if(temp->BT > temp->next->BT){
				swap(temp,temp->next);
				listChanged = 1;
			}
			temp = temp->next;
		}

	}while(listChanged);

}


void addGantt(int id,int st,int ft,int tat,int wt){
	struct gantt*  newNode = (struct gantt*)malloc(sizeof(struct gantt));
	newNode->id = id;
	newNode->st = st;
	newNode->ft = ft;
	newNode->tat = tat;
	newNode->wt = wt;
	newNode->next = NULL;

	if(ghead == NULL){
		ghead =  newNode;
	}else{
		struct gantt* temp = ghead;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}



void ganttChart(){
	int st=0;
	int ft=0;
	int tat;
	int wt;
	struct process* temp = head;
	printf("\n----------------------------\nGANTT CHART\n---------------------------------\n");
	printf("\nStart Time\tProcess id\tFinish Time\n");
	printf("--------------------------------------------\n");
	while(temp != NULL){
		/*if(temp == head && head->AT != 0){
			printf("\n%d\t\tCPU IDLE\t%d",st,temp->BT);
			st = temp->BT;
		}else{*/
			ft = st + temp->BT;
			printf("\n%d\t\tProcess %d\t%d",st,temp->id,ft);
			tat = ft - temp->AT;
			wt = tat - temp->BT;
			addGantt(temp->id,st,ft,tat,wt);
			st = ft;
		//}
		temp = temp->next;
	}

}




void times(){
	printf("\n-------------------\nTurnaround time and Wait Time\n----------------------\n");
	struct gantt* temp = ghead;
	int totalTAT=0;
	int totalWT = 0;
	printf("\nProcess Id\tTurnaround Time\tWait Time");
	while(temp != NULL){
		totalTAT += temp->tat;
		totalWT += temp->wt;
		printf("\n%d\t\t%d\t\t%d",temp->id,temp->tat,temp->wt);
		temp = temp->next;
	}
	float t = ((float)totalTAT/n);
	float w = ((float)totalWT/n);
	printf("\nAverage Turnaround Time : %.2f ",t);
	printf("\n Average Wait Time : %.2f",w);
	return;
}



int main(){
	n=-1;
	do{
		printf("\nEnter number of processes : ");
		scanf("%d",&n);	
	}while(n < 1);
	for(int i=0;i<n;i++){
		int at = -1;
		int bt = -1;
		printf("\nFor process id : %d",i);
		
		do{
			printf("\nEnter Arrival Time : ");
			scanf("%d",&at);
		}while(at < 0);
		do{
			printf("Enter Burst Time : ");
			scanf("%d",&bt);
		}while(bt < 0);

		addProcess(i,at,bt);
		printf("\n-------------------------------------\n");
	}
	// all process added
	printAll();
	sjfAlgorithm();
	//printAll();
	ganttChart();
	times();

}
