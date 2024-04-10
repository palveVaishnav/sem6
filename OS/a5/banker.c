#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int n;
int m;

int *available;
int **max;
int **allocation;
int **need;

int *work;
int *safeseq;
int *finish;

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
	work = (int *)malloc(sizeof(int) * m)
	max = (int **)malloc(sizeof(int *) * n);
	allocation = (int **)malloc(sizeof(int *) * n);
	need = (int **)malloc(sizeof(int *) * n);

	// Total available instances
	printf("\nEnter Available (total) : ");
	for(int j=0;j<m;j++){
		printf("Resource type %c : ", i + 65);
	}
	return;

}




int main(){
	
	resourceAllocation();

	free(need);
	free(max);
	free(allocation);
	free(available);
	free(work);
	free(safeSeq);
	free(finish);
	return 0;


}


