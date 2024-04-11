#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int npages;
int nframes;
int **frame;
int *page;
int pageFault;
int track = 0;


void printFrame(){
	printf("\n[");
	for(int i=0;i<nframes;i++){
		printf("\t%d",frame[i][0]);
	}
	printf("\t]\n");
	return;
}

bool isPresent(int p){
	// increment the counter to track
	for(int i=0;i<nframes;i++){
		if(frame[i][0] == p){
			frame[i][1] = ++track;
			printf("\n\tX\n");
			return true;
		}		
	}
	return false;
}

int leastUsed(){
	// find smaller counter  and return index
	int smallC = frame[0][1];
	int toReplace = 0;
	for(int i=0;i<nframes;i++){
		if(frame[i][1] < smallC){
			smallC = frame[i][1];
			toReplace = i;
		}
	}
	return toReplace;
}



void LRUAlgorithm(){
	pageFault = 0;

	for(int i=0;i<npages;i++){
		if(!isPresent(page[i])){
			// if not present
			// frame with smallest frame[i][1] will be replaced
			int toReplace = leastUsed();
			
			frame[toReplace][0] = page[i];
			frame[toReplace][1] = ++track;
			pageFault++;
			printFrame();

		}
	}
	return;
}


int main(){
	do{
		printf("\nEnter number of Pages : ");
		scanf("%d",&npages);
	}while(npages < 1);
	
	page = (int *)malloc(sizeof(int)*npages);
	
	printf("\nEnter page referance string : \n");
	for(int i=0;i<npages;i++){
		printf("Page[%d] : ",i+1);
		scanf("%d",&page[i]);
	}
	
	do{
		printf("\nEnter number of Frames : ");
		scanf("%d",&nframes);
	}while(nframes < 1);

	frame = (int**)malloc(sizeof(int*) * nframes );
	for(int i=0;i<nframes;i++){
		frame[i] = (int*)malloc(sizeof(int)*2);
		frame[i][0] = 0;
		frame[i][1] = 0;
	}

	LRUAlgorithm();
	printf("\nTotal Page Faults  :  %d",pageFault);
	return 0;
}





