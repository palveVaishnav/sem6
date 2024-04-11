#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int n;
int *bitvector;
int freeBlocks;

struct directEntry
{
	char fileName[20];
	int start;
	int length;
	struct directEntry *next;
};

struct directEntry *head = NULL;

void showVector()
{
	printf("\nThe Bit Vector : \n");
	printf("< ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", bitvector[i]);
	}
	printf(" >\n");
}

bool searchFile(char *fileName)
{
	struct directEntry *temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->fileName, fileName) == 0)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int searchSpace(int length)
{
	// 0 - allocated , 1 - free
	int flag;
	for (int i = 0; i < n; i++)
	{
		if (bitvector[i] == 1)
		{ // if a bit is free
			flag = 0;
			for (int j = i; j < i + length; j++)
			{
				if (bitvector[j] == 0)
				{
					flag++; // if a bit is allocated in betn i and i+length
					break;	// break out of for loop
				}
			}
			if (flag == 0)
			{
				return i;
			}
		}
	}

	return -1;
}

void createFile()
{
	char fileName[20];
	int length;
	do
	{
		printf("\nEnter File Name : ");
		scanf("%s", fileName);
		if (searchFile(fileName))
		{
			printf("\nAlready Exists !!");
		}
	} while (searchFile(fileName));
	do
	{

		// printf("Free Blocks : %d ",freeBlocks);
		printf("\nEnter file Length : ");
		scanf("%d", &length);
		if (length > freeBlocks)
		{
			printf("\nNot Enough Space");
			return;
		}
	} while (length < 1);

	int space = searchSpace(length);
	printf("Space :%d", space);
	if (space != -1)
	{
		struct directEntry *newNode = (struct directEntry *)malloc(sizeof(struct directEntry));
		strcpy(newNode->fileName, fileName);
		newNode->start = space;
		newNode->length = length;
		newNode->next = NULL;
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			struct directEntry *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
		// change bit vector
		for (int i = space; i < space + length; i++)
		{
			bitvector[i] = 0;
		}
		printf("\nFile Created Successfullly !!");
		freeBlocks -= length;
	}
	else
	{
		printf("\nNot Enough Space !!");
	}
	return;
}

void showDirectory()
{
	printf("\n---------------------------");
	printf("\nThe Directory : ");
	struct directEntry *temp = head;
	while (temp != NULL)
	{
		printf("\nFIle Name : %s", temp->fileName);
		printf("\nStart index : %d", temp->start);
		printf("\nLength : %d", temp->length);
		printf("\n-------------------");
		temp = temp->next;
	}
	return;
}

void deleteNode(struct directEntry *node)
{
	for (int i = node->next->start; i < (node->next->start + node->next->length); i++)
	{
		bitvector[i] = 1;
	}
	node->next = node->next->next;
	return;
}

void deleteFile()
{
	if (head == NULL)
	{
		printf("\nEmpty Directory !!");
		return;
	}
	char fileName[20];
	printf("\nEnter File Name : ");
	scanf("%s", fileName);
	struct directEntry *temp = head;
	if (strcmp(head->fileName, fileName) == 0)
	{
		freeBlocks += head->length;
		for (int i = head->start; i < (head->start + head->length); i++)
		{
			bitvector[i] = 1;
		}
		head = head->next;
		printf("\nFile DELETED SUCCESFULLY !!! ");
		return;
	}
	while (temp->next != NULL)
	{
		if (strcmp(temp->next->fileName, fileName) == 0)
		{
			// file found
			// change bit vecto
			freeBlocks += temp->next->length;
			for (int i = temp->next->start; i < (temp->next->start + temp->next->length); i++)
			{
				bitvector[i] = 1;
			}
			// remove from list
			temp->next = temp->next->next;
			printf("\nFile Deleted Successfully !!");
			return;
		}
		temp = temp->next;
	}
	printf("\nFile Does Not Exists !!");
	return;
}

int main()
{
	n = -1;
	while (n < 1)
	{
		printf("\nEnter n : ");
		scanf("%d", &n);
	}
	bitvector = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		bitvector[i] = 1;
	}
	freeBlocks = n;
	bool stop = true;
	while (stop)
	{
		int ch = -1;
		printf("\n-----------------------------");
		printf("\nTotal Blocks : %d", n);
		printf("\nUsed Blocks : %d", n - freeBlocks);
		printf("\nFree Blocks : %d", freeBlocks);
		printf("\n1.Show Bit Vector\n2.Create New File\n3.Show Directory\n4.Delete File\n5.Exit");
		printf("\nEnter Your Choise : ");
		scanf("%d", &ch);
		switch (ch)
		{
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
			stop = false;
			return 0;
			break;
		default:
			printf("\nInvalid Choise!!");
			break;
		}
	}

	return 0;
}
