/****** Shortest Job First Scheduling Non-Prepmtive ***********/
/****** B414009 - Jahangir Ali Khan ************/

#include <stdio.h>

int sort(int temp[], int n, int bt[])
{
	int i, minx = 65000, ret=0;

	for(i=0; i<n; i++)
	{
		if(temp[i] == -1)
			break;
		if(bt[temp[i]]<min)
		{
			min = bt[temp[i]];
			ret = temp[i];
		}
	}
	return ret;
}

int brk (int at[], int n)
{
	int ret = 1, i;

	for (i=0;i<n;i++)
	{
		if(at[i] != 65000)
		{
			ret = 0;
			break;
		}
	}

	return ret;
}

int main()
{
	/* code */
	int n;

	printf("Enter number of process:\n");
	scanf("%d", &n);

	int at[n],bt[n],ct[n],ta[n],wt[n],at2[n];
	int i,j=0;
	for (i=0;i<n;i++)
	{
		printf("For process %d:\n",i);
		printf("Enter arrival time: ");
		scanf("%d",&at[i]);
		at2[i]=at[i];
		printf("Enter burst time: ");
		scanf("%d",&bt[i]);
	}

	int temp[n];
	int t = 0;

	for (int i = 0; i < n; ++i)
	{
		/* code */
		temp[i] = -1;
	}

	while(1)
	{
		j = 0;
		for (int i = 0; i < n ; ++i)
		{
			/* code */
			if (at[i] <= t)
			{
				/* code */
				temp[j] = i;
				j++;
			}
		}
		if (temp[0] == -1)
		{
			/* code */
			t++;
		}
		else
		{
			j = sort(temp,n,bt);
			t = t+bt[j];
			ct[j] = t;
			at[j] = 65000;
		}
		
		for (int i = 0; i < n ; ++i)
		{
			/* code */
			temp[i] = -1;
		}
		if( brk(at,n) == 1)
			break;
	}
	float wt_avg=0.0,ta_avg=0.0;
	for (i=0;i<n;i++)
	{
		printf("For Process %d:\n",i);
		printf("Arrival time: %d\n",at2[i]);
		printf("Burst time: %d\n",bt[i]);
		printf("Completion time: %d\n",ct[i]);
		
		ta[i]=ct[i]-at2[i];
		ta_avg=ta_avg+ta[i];
		
		printf("Turnaround time: %d\n",ta[i]);
		
		wt[i]=ta[i]-bt[i];
		wt_avg=wt_avg+wt[i];
		
		printf("Waiting time: %d\n",wt[i]);
	}

	printf("Average waiting time: %f\n",wt_avg/n);
	printf("Average turnaround time: %f\n",ta_avg/n);

	return 0;
}