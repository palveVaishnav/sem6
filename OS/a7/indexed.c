#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


int n;
int* bitvector;
int freeBlocks;

struct files{
	char fileName[11];
	int length;
	int* index;
	struct files* next;
};

struct files* head = NULL;

void showVector(){
	printf("\nBit Vector : \n");
	printf("< ");
	for(int i=0;i<n;i++){
		printf("%d ",bitvector[i]);
	}
	printf(">\n");
	return;
}

int searchFile(char* fileName){
	struct files* file = head;
	while(file != NULL){
		if(strcmp(fileName,file->fileName)==0){
			return 1;
		}
		file = file->next;
	}
	return 0;
}




void createFile(){
	if(freeBlocks == 0){
		printf("\nDISK FULL !!");
	}
	char fileName[20];
	int flag = 0;
	do{
		printf("\nEnter File Name : ");
		scanf("%s",fileName);
		if(searchFile(fileName)){
			printf("\nFile Already Exists !!");
			//flag++;
		}
	}while(searchFile(fileName));

	int length = 0;
	
	do{
		printf("\nEnter File Length : ");
		scanf("%d",&length);		
	}while(length < 1 );
	if(length > freeBlocks){
		printf("\nFree Space : %d",freeBlocks);
		printf("\nNot Enough Space !!\nRequesting More Than Available\n");
		return;
	}

	// here means space is available 
	// find the 'lenght' locations of 1's in bitvector 
	int* index = (int*)malloc(sizeof(int) * length);
	int track = 0;
	for(int i=0;i<n;i++){
		if(bitvector[i]==1 && track < length){
			index[track++] = i; // add location to structure
			bitvector[i] = 0;  // change status in bitvector
			freeBlocks--;    // decrement free space
		}
		if(track==length){
			break;
		}
	}
	// add the file to files
	struct files* newFile = (struct files*)malloc(sizeof(struct files));
	strcpy(newFile->fileName,fileName);
	newFile->length = length;
	newFile->index = index;
	newFile->next = NULL;
	if(head==NULL){
		head = newFile;
	}else{
		struct files* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newFile;
	}
	printf("\nFile Created Successfully !! ");
	return ;

}

void showDirectory(){
	if(head == NULL){
		printf("\nEmpty Directory !!");
		return;
	}
	struct files* file = head;
	printf("\n---------------------------------\n");
	printf("\n--------- Directory -------------\n");
	printf("\n---------------------------------\n");
	while(file != NULL){
		printf("\nFile Name : %s",file->fileName);
		printf("\nFile Length : %d",file->length);
		printf("\nAllocated Blocks : [ ");
		for(int i=0;i<file->length;i++){
			printf("%d, ",file->index[i]);
		}
		printf("]");
		printf("\n----------------");
		file = file->next;
	
	}
}
	

void deleteFile(){
	char fileName[11];

	printf("\nEnter File Name : ");
	scanf("%s",fileName);
	if(searchFile(fileName)){
		// exists
		// bitvector,freespace and list
		if(strcmp(head->fileName,fileName) == 0){
			for(int i = 0 ; i < head->length ; i++){				
				freeBlocks++;
				bitvector[head->index[i]] = 1;
			}
			head = head->next;
			//printf("\nFile Deleted SUCESFULLY !!");
			//return;
		}else{
			struct files* file = head;
			while(file->next != NULL){
				if(strcmp(file->next->fileName,fileName)==0){
					// bitvector , freeblocks
					for(int i = 0;i < file->next->length ; i++){
						freeBlocks++;
						bitvector[file->index[i]] = 1;
					}
					// files
					file->next = file->next->next;
					//printf("\nFILE DELETED SUCCESSFULLY !!");
					//return;
				}
			}
		}
		printf("\nFile DELETED SUCCESSFULLY !!");
	}else{
		printf("\nFile DOES NOT EXIST !");
	}
	return;
}


int main(){
	n=-1;
	do{
		printf("\nEnter n : ");
		scanf("%d",&n);
	}while(n<1);
	bitvector = (int *)malloc(sizeof(int) * n);
	freeBlocks = 0;
	for(int i=0;i<n;i++){
		bitvector[i] = rand()%2;
		//bitvector[i] = 1;
		if(bitvector[i] == 1){
			freeBlocks++;
		}
	}
	bool stop = true;

	do{
		int ch = -1;
		printf("\n----------------------------------------------------");
		printf("\nTotal DISK SIZE : %d\nFREE BLOCKS : %d\nUSED BLOCKS : %d",n,freeBlocks,n-freeBlocks);
		printf("\n\t1.Show Bit Vector\n\t2.Create New File\n\t3.Show Directory\n\t4.Delete File\n\t5.Exit");
		printf("\n\tEnter Your Choise : ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				showVector();
				break;

			case 2:
				createFile();
				break;

			case 3:
				showDirectory();
				break;

			case 4: 
				deleteFile();
				break;

			case 5:
				printf("\nTerminating Program !!\n");
				stop = false;
				break;

			default:
				printf("Invalid Choisee !! ");
				break;
		}	
	
	}while(stop);
	
}








