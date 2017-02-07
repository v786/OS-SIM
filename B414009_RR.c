/****** Round-Robin Scheduling Prepmtive ***********/
/****** B414009 - Jahangir Ali Khan ************/

#include <stdio.h>

int ip()
{
	int n;
	scanf("%d",&n);
	return n;
}

void sort(int at[],int bt[], int n)
{
	int i, j, temp;
	int x,y;

	for (int i = 0; i < n; ++i)
	{
		/* sort by arrival time */

		temp = 0;

		for (int i = 0; i < n; ++i)
		{
			if (at[temp] > at[i])
			{
				/* compare */
				x = at[i];
				y = bt[i];
				at[i] = at[temp];
				bt[i] = bt[temp];
				at[temp] = x;
				bt[temp] = y;
				temp = i;
			}
		}
	}
}

void print_array(int a[], int b[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("For process %d: at = %d bt = %d \n",i, a[i], b[i]);
	}
}

int main()
{
	/* code */
	int n;
	
	printf("Enter number of processes:\n");
	n = ip();

	int at[n],bt[n],ct[n],ta[n],wt[n],at2[n],bt2[n];

	int i,j=0;

	for (int i = 0; i < n ; ++i)
	{
		/* code */
		printf("For process %d:\n",i);
		printf("Enter arrival time:");
		at[i]= ip();

		printf("Enter burst time:");
		bt[i]= ip();
	}

	int q;
	printf("Enter time quantum");
	q = ip();

	int remain=n;
	int t=0;
	i=0;

	sort(at,bt,n);

	//print_array(at,bt,n);

	for (int i = 0; i < n; ++i)
	{
		/* code */
		at2[i] = at[i];
		bt2[i] = bt[i];
	}

	while(remain!=0)
	{
		if (bt[i] <= q && bt[i]>0)
		{
			/* Check if Process is less than BT and finish it */
			t = t+bt[i];
			bt[i] = 0;
			j = 1;
		}
		else if (bt[i]>0)
		{
			/* Reduce BT of process by time quantum */
			bt[i] = bt[i]-q;
			t = t + q;
		}

		if (bt[i]==0 && j==1)
		{
			/* If a process ends, remove it from remaining queue. */
			remain--;
			ct[i]=t;
			j=0;
		}

		if (i == n-1)
		{
			i=0;
		}
		else if (at[i+1]<=t)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}

	float wt_avg=0.0,ta_avg=0.0;

	for (i=0;i<n;i++)
	{
		printf("For Process %d: ",i);
		printf("Arrival time: %d, ",at2[i]);
		printf("burst time: %d, ",bt2[i]);
		printf("completion time: %d, ",ct[i]);

		ta[i]=ct[i]-at2[i];
		ta_avg=ta_avg+ta[i];

		printf("turnaround time: %d, ",ta[i]);

		wt[i]=ta[i]-bt2[i];
		wt_avg=wt_avg+wt[i];

		printf("waiting time: %d, \n",wt[i]);
	}
	
	printf("Average waiting time: %f, ",wt_avg/n);
	printf("Average turnaround time: %f\n",ta_avg/n);

	return 0;
}