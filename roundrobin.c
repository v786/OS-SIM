/****** Round-Robin Scheduling Prepmtive ***********/
/****** B414009 - Jahangir Ali Khan ************/

#include <stdio.h>

int main()
{
	/* code */
	int n;
	
	printf("Enter number of processes:\n");
	scanf("%d",&n);

	int at[n],bt[n],ct[n],ta[n],wt[n],at2[n],bt2[n];

	int i,j=0;

	for (int i = 0; i < n ; ++i)
	{
		/* code */
		printf("For process %d:\n",i);
		printf("Enter arrival time:");
		scanf("%d",&at[i]);

		at2[i]=at[i];

		printf("Enter burst time:");
		scanf("%d",&bt[i]);
		bt2[i]=bt[i];
	}

	int q;
	printf("Enter time quantum");
	scanf("%d",&q);

	int remain=n;
	int t=0,c=0;
	i=0;

	while(1)
	{
		if (bt[i] <= q && bt[i]>0)
		{
			/* code */
			t = t+bt[i];
			bt[i] = 0;
			j = 1;
		}
		else if (bt[i]>0)
		{
			/* code */
			bt[i] = bt[i]-q;
			t = t + q;
		}

		if (bt[i]==0 && j==1)
		{
			/* code */
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
		printf("For Process %d:\n",i);
		printf("Arrival time: %d\n",at2[i]);
		printf("burst time: %d\n",bt2[i]);
		printf("completion time: %d\n",ct[i]);

		ta[i]=ct[i]-at2[i];
		ta_avg=ta_avg+ta[i];

		printf("turnaround time: %d\n",ta[i]);

		wt[i]=ta[i]-bt2[i];
		wt_avg=wt_avg+wt[i];

		printf("waiting time: %d\n",wt[i]);
	}
	
	printf("Average waiting time: %f\n",wt_avg/n);
	printf("Average turnaround time: %f\n",ta_avg/n);

	return 0;
}