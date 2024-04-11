#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int n;
int p;
int* pages;
int pageFault;
int* frames;
int track;

void printFrame(){
	printf("\n[");
	for(int i=0;i<n;i++){
		printf("\t%d",frames[i]);
	}
	printf("\t]\n");
	return;
}


bool isPresent(int p){
	for(int i=0;i<n;i++){
		if(frames[i] == p){
			return true;
		}
	}
	return false;
}


void fifo(){
	pageFault = 0;
	track = 0;
	// memory frame , pages in the memory at given time
	frames = (int *)malloc(sizeof(int)*n);	
	for(int i=0;i<n;i++){
		frames[i] = -1;
	}

	for(int i=0;i<p;i++){
		// check if the page is present in the frame
		if(isPresent(pages[i])){
			printf("\nX\n");
		}else{
			// add at track
			frames[track++]=pages[i];
			pageFault++;
			printFrame();
			if(track==3){
				track = 0;
			}
		}
	}
	return;
}




int main(){
	n=-1;p=-1;
	do{
		printf("\nEnter Number of pages : ");
		scanf("%d",&p);
	}while(p<1);
	pages = (int *)malloc(sizeof(int) * p);

	printf("\nEnter Pages : ");
	for(int i=0;i<p;i++){
		printf("page %d : ",i+1);
		scanf("%d",&pages[i]);
	}
	
	do{
		printf("\nEnter Number of Frames : ");
		scanf("%d",&n);
	}while(n<1);

	// fifo algorithm
	fifo();
	printf("\nTotal Page Faults : %d\n",pageFault);
	return 0;



}
