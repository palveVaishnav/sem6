#include <stdio.h>
#include <string.h>
struct node
{
	char pname[10];
	int at, bt, bt1, ct, st, tat, wt;
};
char gant_chart[100][100], g[100][100];
void accept(struct node a[], int n)
{

	int i;

	for (i = 0; i < n; i++)
	{
		printf("\n\nEnter process name : ");
		scanf("%s", a[i].pname);
		printf("Enter arrival time : ");
		scanf("%d", &a[i].at);
		printf("Enter the burst time : ");
		scanf("%d", &a[i].bt);
		a[i].bt1 = a[i].bt;
		a[i].st = -1;
	}
}

void sort(struct node a[], int n)
{
	int i, j, temp;
	char sname[10];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j].at > a[j + 1].at)
			{ // arrival time
				temp = a[j].at;
				a[j].at = a[j + 1].at;
				a[j + 1].at = temp;

				// burst time
				temp = a[j].bt;
				a[j].bt = a[j + 1].bt;
				a[j + 1].bt = temp;

				// burst1 time
				temp = a[j].bt1;
				a[j].bt1 = a[j + 1].bt1;
				a[j + 1].bt1 = temp;

				// name
				strcpy(sname, a[j].pname);
				strcpy(a[j].pname, a[j + 1].pname);
				strcpy(a[j + 1].pname, sname);
			}
		}
	}
}

void sjf(struct node a[], int n)
{
	int c_t = 0, minbt, id, n1 = 0, i, j = 0, completed[10] = {0};
	while (n1 != n)
	{
		minbt = 1000;

		for (i = 0; i < n; i++)
		{

			if (completed[i] == 0 && a[i].at <= c_t && a[i].bt < minbt)
			{
				minbt = a[i].bt;
				id = i;
			}
		}
		if (id >= 0)
		{

			if (a[id].st < 0)
			{
				a[id].st = c_t;
				a[id].ct = c_t + 1;
				a[id].bt = a[id].bt - 1;
				a[id].tat = a[id].ct - a[id].at;
				// a[id].wt=a[id].st-a[id].at;
				strcpy(gant_chart[c_t], a[id].pname);

				c_t++;
			}
			else
			{

				a[id].ct = c_t + 1;
				a[id].bt = a[id].bt - 1;
				a[id].tat = a[id].ct - a[id].at;
				a[id].wt = a[id].st - a[id].at;
				strcpy(gant_chart[c_t], a[id].pname);
				c_t++;
			}
			if (a[id].bt == 0)
			{
				completed[id] = 1;
				n1++;
			}
		}
		else
		{
			c_t++;
			strcpy(gant_chart[c_t], "IDLE");
		}
	}
}

void display(struct node a[], int n)
{

	int i = 0, c, max = -1;
	float avg_tat = 0.0, avg_wt = 0.0;

	printf("\n\nTable : \nProcess\t AT \t BT \t ST \t Tat \t CT\t WT\n");
	for (i = 0; i < n; i++)
	{
		if (a[i].ct > max)
			max = a[i].ct;
		a[i].wt = a[i].tat - a[i].bt1;
		printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d", a[i].pname, a[i].at, a[i].bt1, a[i].st, a[i].tat, a[i].ct, a[i].wt);
	}
	printf("\n\nAverage Turnaround time=%f\nAverage Waiting time=%f\n\n", (avg_tat / n), (avg_wt / n));
	printf("\n\nGantt chart\n");

	for (i = 0; i < max; i++)
	{
		printf("%d---%s---%d\n", i, gant_chart[i], i + 1);
	}
}

int main()
{
	struct node a[10];
	int n;

	printf("Enter the number of process : ");
	scanf("%d", &n);

	accept(a, n);
	sort(a, n);
	sjf(a, n);
	display(a, n);

	return 0;
}
