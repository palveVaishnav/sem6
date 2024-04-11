#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dsize, used = 0;
int *D = NULL;

struct info
{
	char fname[10];
	int start, length;
	struct info *next;
};

struct info *E = NULL, *lastEntry = NULL;

#define ENTRY (struct info *)malloc(sizeof(struct info))

int search(int length)
{
	int i, j, flag = 1, blknum;
	for (i = 0; i < dsize; i++)
	{
		if (D[i] == 1)
		{
			flag = 1;
			for (blknum = i, j = 0; j < length; j++)
			{
				if (D[blknum++] == 1)
					continue;
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				return i;
		}
	}

	return -1;
}


void allocate()
{
	char fname[10];
	int length, blknum, i, flag = 0, cnt = 0, avail;
	struct info *t;
	struct info *s = E;
	for (i = 0; i < dsize; i++)
	{
		if (D[i] == 0)
		{
			cnt++;
		}
	}
	avail = dsize - cnt;
	if (cnt > dsize)
	{
		printf("\nNo disk space available");
		return;
	}

	do
	{
		printf("\nEnter filename: ");
		scanf("%s", fname);
		flag = 1;
		if (E != NULL)
		{
			for (s = E; s != NULL; s = s->next)
			{
				if (strcmp(s->fname, fname) == 0)
				{
					printf("\nFile already exists.");
					flag = 0;
					break;
				}
			}
		}
	} while (flag == 0);

	do
	{
		printf("\nEnter length of file: ");
		scanf("%d", &length);
		if (length > dsize || avail < length)
		{
			printf("\nNo disk space available");
			return;
		}
		if (length <= 0)
			printf("\nInvalid length");
	} while (length <= 0);

	if (length <= dsize - used)
		blknum = search(length);
	else
		blknum == -1;

	if (blknum <= -1)
		printf("\nNo disk space available.");
	else
	{
		printf("\nBlock allocated.");
		used = used + length;
		t = ENTRY;
		strcpy(t->fname, fname);
		t->start = blknum;
		t->length = length;
		t->next = NULL;

		if (E == NULL)
			E = lastEntry = t;
		else
		{
			lastEntry->next = t;
			lastEntry = lastEntry->next;
		}

		for (i = 1; i <= length; i++)
			D[blknum++] = 0;
	}
}

void deallocate()
{
	if (E == NULL)
	{
		printf("\nNothing to delete");
		return;
	}
	struct info *f, *s;
	char fname[10];
	int start, length, i, blknum, flag = 0;
	printf("\nEnter filename to delete: ");
	scanf("%s", fname);

	for (s = E; s != NULL; s = s->next)
	{
		if (strcmp(s->fname, fname) == 0)
		{
			flag = 1;
			start = s->start;
			length = s->length;
			for (blknum = start, i = 0; i < length; i++)
				D[blknum++] = 1;
			printf("\nBlock status after deallocation:");
			for (i = 0; i < dsize; i++)
				printf("%d", D[i]);
			if (s == E)
			{
				E = E->next;
				free(s);
				used = used - length;
				break;
			}
			for (f = E; f->next != s; f = f->next)
			{
			}
			f->next = s->next;
			free(s);
			used = used - length;
			break;
		}
	}
	if (flag == 0)
		printf("\nNo such file or directory.");
}
void display_entry()
{
	if (E == NULL)
	{
		printf("\nDirectory is empty");
		return;
	}

	struct info *t;
	printf("\nDirectory Contents: ");
	printf("\nFNAME\tSTART\tSIZE\n");
	for (t = E; t != NULL; t = t->next)
	{
		printf("\n%s\t%d\t%d", t->fname, t->start, t->length);
	}
	printf("\nUSED BLOCK =%d", used);
	printf("\nFREE BLOCK = %d", dsize - used);
}

void init_disk()
{
	int i;
	D = (int *)malloc(sizeof(int) * dsize);
	for (i = 0; i < dsize; i++)
		D[i] = 1;
}

int main()
{
	int choice, i;
	do
	{
		printf("\nEnter the size of disk: ");
		scanf("%d", &dsize);
		if (dsize <= 0)
			printf("\nInvalid disk size.");
	} while (dsize <= 0);

	init_disk();

	while (1)
	{
		printf("\nMENU: \n1. Show Bit Vector \n2.Create new file\n3. Show directory\n4. Delete file \n5. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			for (i = 0; i < dsize; i++)
				printf("%d", D[i]);
			break;
		case 2:
			allocate();
			break;
		case 3:
			display_entry();
			break;
		case 4:
			deallocate();
			break;
		case 5:
			exit(0);
		}
	}
}
