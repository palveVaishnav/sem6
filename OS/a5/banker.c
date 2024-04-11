#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int n;
int m;

int *available;
int **max;
int **allocation;
int **need;

int *work;
int *safeSeq;
int *finish;



void printArray(int **a){
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return;
}



void calculateNeed(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
}

void resourceAllocation(){
	n=-1,m=-1;
	do{
		printf("\nNumber of Processes : ");
		scanf("%d",&n);
	}while(n<1);
	do{
		printf("Number of Resource Types : ");
		scanf("%d",&m);
	}while(m<1);

	// allocate memory
	available = (int *)malloc(sizeof(int)* m);
	work = (int *)malloc(sizeof(int) * m);

	max = (int **)malloc(sizeof(int *) * n);
	allocation = (int **)malloc(sizeof(int *) * n);
	need = (int **)malloc(sizeof(int *) * n);

	safeSeq = (int *)malloc(sizeof(int ) * n);
	finish = (int *)malloc(sizeof(int) * n);

	for(int i=0;i<n;i++){
		max[i] = (int *) malloc(sizeof(int ) * m);
		allocation[i] = (int *)malloc(sizeof(int) * m);
		need[i] = (int *)malloc(sizeof(int ) * m);

		for(int j=0;j<m;j++){
			available[j] = -1;
			work[j] = -1;
			
			max[i][j] = -1;
			allocation[i][j] = -1;
			need[i][j] =-1;
			
			safeSeq[i] = -1;
			finish[i] = 0;
		}
	}

	// Total available instances
	printf("\nEnter Available (total) : ");
	for(int j=0;j<m;j++){
		do{
			printf("\nResource type %c : ", j + 65);
			scanf("%d",&available[j]);
			work[j] = available[j];
		}while(available[j] < 1);
	}

	//available->max->allocation->need;
	printf("\n------ Enter MAX MATRIX --------\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){			
			do{
				printf("MAX[P%d][%c] : ",i,j+65);
				scanf("%d",&max[i][j]);
				if(max[i][j] < 0){
					printf("Less that ZERO !! \n");
				}
				if(max[i][j] > available[j]){
					printf("Greater than AVAILABLE !! \n");
				}
			}while(max[i][j] < 0 || max[i][j] > available[j]);
		}
		printf("\n-------------------------------\n");
	}

	printf("\n--------- Enter ALLOCATION MATRIX ------------\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			do{
				printf("AVAILABLE[P%d][%c] : ",i,j+65);
				scanf("%d",&allocation[i][j]);
				if(allocation[i][j] > max[i][j]){
					printf("More Than MAX !! \n");
				}
				if(allocation[i][j] < 0){
					printf("Less than ZERO\n");
				}
			}while(allocation[i][j] > max[i][j] || allocation[i][j] < 0);
		}
		printf("\n--------------------------------\n");
	}

	// Calculate Need
	calculateNeed();
	// calculate now work
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			work[j] = work[j] - allocation[i][j];
		}
	}
	return;
}


bool isSafe(){
	// checks if the present system is in safe state of  not
	int s=0;
	int flag;

	for(int k=0;k<(2*n);k++){
		
		for(int i=0;i<n;i++){
			
			if(finish[i] == 0){
				flag = 0;

				for(int j=0;j<m;j++){
					if(need[i][j] > work[j]){
						flag++;
					}
				}
				if(flag==0){
					// allocate 
					safeSeq[s++] = i;
					for(int j=0;j<m;j++){
						work[j] = work[j] + allocation[i][j];
						//allocation[i][j] = 0;
					}
					finish[i]++;
				} 
			}
		}
	} // 2n
	// check if all processes are executed or not
	flag = 0;
	for(int i=0;i<n;i++){
		if(finish[i] == 0){
			flag++;
		}
	}
	if(flag==0){
		return true;
	}else{
		return false;
	}

}


void requestAllocation(){
	int* request = (int *)malloc(sizeof(int) * m);
	int pid = -1;
	do{
		printf("\nEnter process id(0-n) : ");
		scanf("%d",&pid);
	}while(pid < 0 || pid >= n);
	printf("\nEnter Requesting resources : ");
	for(int i=0;i<m;i++){
		do{			
			printf("\nREQUEST[%d] : ",i);
			scanf("%d",&request[i]);
			if(request[i] > available[i]){
				printf("\nMore than Available !!\tTry Again !!\n");
			}
			if((request[i] + allocation[pid][i]) > max[pid][i]){
				printf("\nMore Than Max \n");
			}

		}while(request[i] < 0 || request[i] > available[i] || ( request[i] + allocation[pid][i] ) > max[pid][i]); 
		
		// valid request , allocate to that process
		allocation[pid][i] = allocation[pid][i] + request[i];
	}
	// allocation is changed for a particular row
	// calculate new need and work
	calculateNeed();
	// assign total available and then caculate again
	for(int j =0;j<m;j++){
		work[j] = available[j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			work[j] = work[j] - allocation[i][j];
		}
	}
	printf("\nWORK\n");
	for(int j=0;j<m;j++){
		printf("%d\t",work[j]);
	}

	bool safe = isSafe();
	if(safe){
		printf("\nSAFE STATE !!");
		printf("\nSAFE SEQUENCE : ");
		for(int i=0;i<n;i++){
			printf("->%d",safeSeq[i]);
		}
	}else{
		printf("\nNot SAFE");
	}
	printf("\nMAX\n");
	printArray(max);
	printf("\nAllocation\n");
	printArray(allocation);
	printf("\nNeed\n");
	printArray(need);
	return;
}






int main(){
	
	resourceAllocation();
	printArray(max);
	printArray(allocation);
	printArray(need);
	printf("\nWork Vector : ");
	for(int j=0;j<m;j++){
		printf("%d\t",work[j]);
	}

	bool safe = isSafe();
	if(safe){
		printf("\nSystem is in SAFE STATE !!");
		printf("\nSafe Sequence is : \n");
		for(int i=0;i<n;i++){
			printf("->P%d",safeSeq[i]);
		}		
	}else{
		printf("\nSystem is Not in SAFE STATE");
	}

	char ch;
	do{
		printf("\nDo you want to Continue (y/n) : ");
		scanf("%c",&ch);
		if(ch == 'y'){
			requestAllocation();
		}
	}while(ch != 'n');

	free(need);
	free(max);
	free(allocation);
	free(available);
	free(work);
	free(safeSeq);
	free(finish);
	return 0;


}
