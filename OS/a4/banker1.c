#include<stdio.h>
#include<stdlib.h>

int n; //resources
int m; // types

int **max;
int **need;
int **allocation;
int *available;
int *work;

void printArray(int ** a){
	printf("\n");
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}


void isSafe(){
	int *safeSequence = (int *)malloc(sizeof(int )* n);
	int flag;
	int s=0;
	int *finish = (int *)malloc(sizeof(int ) * n );

	for(int i=0;i<n;i++){
		finish[i] = 0; // set all process to zero ( not executed )
	}
	for(int k =0;k< (n*2);k++){ // traversing 2n times , to be sure that traversed enough times.
		
		for(int i =0;i<n;i++){

			if(finish[i]==0){   // the process is not executed yet
				flag =0;
				for(int j=0;j<m;j++){
					if(need[i][j] > work[j]){;
						flag=1; // not enough resources
					}
				}
				if(flag ==0){ //resources can be allocated 
					safeSequence[s++]= i;  // add process to safe sequence
					for(int j=0;j<m;j++){  //after allocation, add the allocated resources to work
						work[j] = work[j] + allocation[i][j];
					}
					finish[i]++;   // mark the process as complete
				}			
			}
		}


	} 
	flag = 0;
	for(int i=0;i<n;i++){
		if(finish[i]==0){
			flag++;     // if a processs is still not executed
		}
	}
	if(flag == 0){
		// safe 
		printf("\nThe System is in SAFE STATE.");
		printf("\nSAFE SEQUENCE :   ");
		for(int i=0;i<n;i++){
			printf("->%d",safeSequence[i]);
		}
	}else{
		printf("\nThe System is NOT in SAFE STATE !!! ");
	}
	free(finish);
	free(safeSequence);
	return;
}




int main(){
	n=-1;
	m= -1;
	do{
		printf("Enter number of processes : ");
		scanf("%d",&n);
	}while(n < 1 );
	do{
		printf("Enter types of Resources : ");
		scanf("%d",&m);
	}while(m< 1);

	need = (int **)malloc(sizeof(int *) * n);
	max = (int **)malloc(sizeof(int *) * n);
	allocation = (int **)malloc(sizeof(int *) * n);

	for(int i=0;i<n;i++){
		need[i] = (int * )malloc(sizeof(int ) * m) ;
		max[i] = (int *)malloc(sizeof(int ) * m);
		allocation[i] = (int * )malloc(sizeof(int) * m);
		for(int j =0 ;j<m;j++){
			need[i][j] = -1;
			max[i][j] = -1;
			allocation[i][j] = -1;
		}
	}
	available = (int *)malloc(sizeof(int ) * m);
	
	printf("\nAvailable Vector:\n");
	for(int i=0;i<m;i++){
		available[i] = -1;
		printf("%d\t",available[i]);
	}
	/*
	printf("\nNeed Matrix :");
	printArray(need);
	printf("Max Matrix : ");
	printArray(max);
	printf("Allocation Matrix : ");
	printArray(allocation);
	*/
	printf("\nEnter Available Resources (total Available, before allocation) : \n");
	for(int i=0;i<m;i++){
		do{
			printf("Resource type %c : ",i+65);
			scanf("%d",&available[i]);
		}while(available[i] < 0);
	}

	//accepting max
	printf("\n---------------------------------");
	printf("\n------ Enter Max matrix ---------");
	printf("\n---------------------------------");
	for(int i=0;i<n;i++){
		printf("\nFor Process %d : \n",i);
		for(int j=0;j<m;j++){
			do{
				printf("MAX[%d][%d] : ",i,j);
				scanf("%d",&max[i][j]);
				if(max[i][j] < 0){
					printf("Error : max can't be less than zero!!\n");
				}
				if(max[i][j] > available[j]){
					printf("Error : max can't be greater than available !!\n");
				}

			}while(max[i][j] < 0 || max[i][j] > available[j]);
		}
		printf("\n-----------------------------------");
	}

	//Accept Allocation
	printf("\n----------------------------------");
	printf("\n---- Enter Allocation Matrix -----");
	printf("\n----------------------------------");

	for(int i=0;i<n;i++){
		printf("\nFor Process %d :\n",i);
		for(int j=0;j<m;j++){
			do{
				printf("Allocation[%d][%d] : ",i,j);
				scanf("%d",&allocation[i][j]);
				if(allocation[i][j] < 0 ){
					printf("Error : Can't be less than ZERO !!!\n");
				}
				if(allocation[i][j] > max[i][j]){
					printf("Error : More than required !!\n");
				}

			}while(allocation[i][j] < 0 || allocation[i][j] > max[i][j]);
		}
		printf("\n----------------------");
	}

	// Calculate now available
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			available[j] = available[j] - allocation[i][j];
		}
	}
	// Calculate Need matrix 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			need[i][j] = max[i][j] - allocation[i][j];

		}
	}
	printf("\nMax Matrix :\n");
	printArray(max);
	printf("\nAllocation Matrix : \n");
	printArray(allocation);
	printf("\nNeed Matrix : \n");
	printArray(need);
	printf("\nAvailable : (now)\n");
	work = (int *)malloc(sizeof(int )* m);
	//copy available to work
	for(int i = 0 ;i<m;i++){
		work[i] = -1;
		work[i] = available[i];
		printf("%d\t",work[i],available[i]);

	}


	isSafe();
	free(need);
	free(max);
	free(available);
	free(work);
	//free(finish);
	free(allocation);
	//free(safeSequence);
	return 0;

}





























