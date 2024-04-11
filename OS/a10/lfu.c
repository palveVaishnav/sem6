#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int nframes=-1;
int npages=-1;
int **frame;
int *page;

int clock = 1;
int pageFaults = 0;

int smallestCount(){
	int smallest = 0;
	for(int i=0;i<nframes;i++){
		if(frame[smallest][1] == frame[i][1]){
			if(frame[smallest][2] > frame[i][2]){
				smallest = i;
			}
		}
		if(frame[smallest][1] > frame[i][1]){
			smallest = i;
		}
	}
	return smallest;
}


int highestCount(){
	int high = 0;
	for(int i=0;i<nframes;i++){
		if(frame[i][0] == -1){
			return i;
		}
		if(frame[high][1]==frame[i][1]){ // same counter
			if(frame[high][2] > frame[i][2]){
				high = i;
			}
		}
		if(frame[high][1] < frame[i][1]){ // checking highest counter
			high = i;
		}
	}
	return high;
}

bool isPresent(int p){
	for(int i=0;i<nframes;i++){
		if(frame[i][0] == p){
			// page is present
			frame[i][1]++; // increment the counter
			frame[i][2] = ++clock; // increment clock
			printf("\n\t\tX\n");
			return true;
		}
	}
	return false;
}


void printFrame(){
	printf("\n[");
	for(int i=0;i<nframes;i++){
		printf("\t%d",frame[i][0]);
	}
	printf("\t]\n");
	return;
}

void LFUAlgorithm(){	
	for(int i=0;i<npages;i++){
		if(!isPresent(page[i])){
			//int toReplace = smallestCount();  // for lfu 
			int toReplace = highestCount();   // for mfu
			frame[toReplace][0] = page[i];
			frame[toReplace][1] = 1;
			frame[toReplace][2] = ++clock;
			printFrame();
			pageFaults++;
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
	printf("\nEnter Page Refrence String \n");
	for(int i=0;i<npages;i++){
		printf("Page[%d] : ",i);
		scanf("%d",&page[i]);
	}
	do{
		printf("\nEnter number of Frames : ");
		scanf("%d",&nframes);
	}while(nframes < 1);

	frame = (int **) malloc(sizeof(int) * nframes);
	for(int i=0;i<nframes;i++){
		frame[i]  = (int*)malloc(sizeof(int) * 3);
		frame[i][0] = -1; //page
		frame[i][1] = -1; //counter
		frame[i][2] = -1; //timer
	}
	
	LFUAlgorithm();
	printf("\nTotal Page Faults : %d ",pageFaults);
	return 0;
}



