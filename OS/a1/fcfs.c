#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct process{
	int id;
	int AT;
	int BT;
	struct process* next;
};
struct process *head = NULL;

void addProcess(int id,int at,int bt){
	// ceate a node and then append that node to the linked list
	struct process *newNode = (struct process *) malloc (sizeof(struct process));
	if(newNode == NULL){
		printf("Node not Created");
	}

	//add data to the node
	newNode->id = id;
	newNode->AT = at;
	newNode->BT = bt;
	newNode->next = NULL;

	// Add node to the linked list
	if(head == NULL){
		// if list is empty
		head = newNode;
	}else{
		// temp node to traverse the list
		struct process *last = head;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = newNode;
	}

	printf("\nProcess Added...");
	return ;
}

void printAll(){
	struct process* temp = head;
	printf("\n-----------------------\nAll entered processes\n--------------------------");
	while(temp!= NULL){
		printf("\nid : %d\nArrival time : %d\nBurst Time :%d",temp->id,temp->AT,temp->BT);
		printf("\n--------------------------");
		temp = temp->next;
	}
}


void swap(struct process* a,struct process* b){
	//id
	int id = a->id;
	a->id = b->id;
	b->id = id;

	//at
	int at = a->AT;
	a->AT = b->AT;
	b->AT = at;

	//bt
	int bt = a->BT;
	a->BT = b->BT;
	b->BT = bt;

	return;
}


void fcfsAlgorithm(){
	// sort process according to their arrival time ....
	int listChanged;

	if(head == NULL){
		return;
	}

	do{
		listChanged = 0;
		struct process *temp = head;
		while(temp->next != NULL){			
			if(temp->AT > temp->next->AT){
				swap(temp,temp->next);
				listChanged = 1;
			}
			temp = temp->next;
		}
	}while(listChanged);
	

}
 
void ganttChart(){
	printf("\n------------------------\nGantt Chart\n-----------------------\n");
	printf("\nStart time\tProcess Id\tFinish Time\tTurnAround Time\tWait Time");
	printf("\n---------------------------------------------------------------------------------");
	int st = 0;
	int ft = 0;
	int tat = 0,wt = 0;
	int totalTAT = 0,totalWT = 0;
	struct process* temp = head;
	int n =0;
	while(temp != NULL){
		/*if(st == 0){
			printf("\n%d \t\t CPU IDLE \t\t %d \t\t -- \t\t --",st,temp->AT);
			st = temp->AT;
		}else{*/
			ft = st + temp->BT;
			tat = ft - temp->AT;
			wt = tat - temp->BT;
			printf("\n %d\t\tProcess %d\t\t%d\t\t %d\t\t %d",st,temp->id,ft,tat,wt);
			st = ft;
			totalTAT += tat;
			totalWT += wt;
			n++;
		//}
		temp = temp->next;
	}
	printf("\nAverage TAT : %.2f ", (float)(totalTAT/n));
	printf("\nAverage WT : %.2f ", (float)(totalWT/n));
	return;
}

int main(){
	int n=-1;
	do{
		printf("\nEnter n : ");
		scanf("%d",&n);
	}while(n < 1);
	for(int i=0;i<n;i++){
		int at = -1,bt = -1;
		printf("\nFor process id : %d",i);
		do{
			printf("\nEnter the Arrival time : ");
			scanf("%d",&at);
		}while(at < 0);
		do{
			printf("Enter the Burst time : ");
			scanf("%d",&bt);
		}while(bt < 0);
		addProcess(i,at,bt);
		printf("\n------------------------------");
	}//forloop
	
//	printAll();
	fcfsAlgorithm();
	printAll();
	ganttChart();
	return 0;
}//main
