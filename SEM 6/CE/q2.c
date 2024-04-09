#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct pcb
{
	int pid,bt,prt;
	 float at,ct,wt,tat;
	struct pcb *next;
} *head=NULL;



void main()
{

	struct pcb *new, *current;
	float arr_time;
	int i,id,n,burst_time,priority;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter arrival time: ");
	scanf("%f",&arr_time);
	for(i=0;i<n;i++)
	{
		new=(struct pcb*)malloc(sizeof(struct pcb));

        
       
		//same arrival time
		new->at=arr_time;
		
		printf("\nEnter the process ID:  ");
		scanf("%d",&id);
		new->pid=id;
		
		
	    printf("\nEnter the priority: ");
		scanf("%d",&priority);
		new->prt=priority;
		
		

		printf("\nEnter the Burst time: ");
		scanf("%d",&burst_time);
		new->bt=burst_time;
		new->next=NULL;

		if(head==NULL)
		{
			head=current=new;
			
		}
		else
		{
			current=head;
			while(current->next!=NULL)
			{
				current=current->next;
			
			}
			current->next=new;
		}
		
	}

	printf("\nBefore sorting the process \n");
	printf("\nProcess ID\t\t\t Arrival time\t\t\tBurst time\t\t\tPriority");
	current=head;
	while(current!=NULL)
	{
		printf("\n%d\t\t\t\t%f\t\t\t\t%d\t\t\t\t%d\t\t\t\t",current->pid,current->at,current->bt,current->prt);
		current=current->next;
	}

	//Sorting according to priority
	
	int swapped, tmp, tmp1;
	struct pcb *ptr1;
	
	if(head==NULL)
		return;
	do
	{
		swapped=0;
		current=head;
		while(current->next!=NULL)
		{
			if(current->prt>current->next->prt)
			{
				tmp1=current->prt;
				current->prt=current->next->prt;
				current->next->prt=tmp1;

				tmp=current->bt;
          		       current->bt=current->next->bt;
                		current->next->bt=tmp;

				tmp=current->pid;
             		     current->pid=current->next->pid;
              		    current->next->pid=tmp;
		
				swapped=1;
			}
			    ptr1=ptr1->next;
		}
	}while(swapped);

	printf("\nAfter sorting the processes\n");
	printf("\nProcess ID\t\t\t Arrival time\t\t\tBurst time\t\t\tPriority");
        current=head;
      // while(current!=NULL)
      
      for(i=0;i<n;i++)
        {
                printf("\n%d\t\t\t\t%f\t\t\t\t%d\t\t\t\t%d\t\t\t\t",current->pid,current->at,current->bt,current->prt);
                current=current->next;
                
        }
        
       // float wait=0;
        float k=arr_time;
        current=head;
        while(current)
        {
            
            k=k+current->bt;
            current->ct=k;
            current->tat=current->ct-current->at;
            current->wt=current->tat-current->bt;
            current=current->next;
            
            
        }

        printf("\n\n\n*******Process Details*******\n");
		printf("\nProcess\t\tArrival time\t\tBurst time\t\tcompletion time\t\t\t TAT\t\t\tWaiting time\t\n");

		current=head;
		float total_wt=0, total_tat=0;
		while(current)
		{
			printf("%d\t\t%f\t\t%d\t\t\t%f\t\t\t%f\t\t%f\n",current->pid,current->at,current->bt,current->ct,current->tat,current->wt);
			total_wt=total_wt+current->wt;
			total_tat=total_tat+current->tat;
			current=current->next;
		}
		printf("\nAverage turnaround time: %f \n Average waiting time : %f\n",total_tat/n,total_wt/n);

}
