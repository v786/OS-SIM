/****** Shortest Job First Scheduling Prepmtive ***********/
/****** B414009 - Jahangir Ali Khan ************/

#include <stdio.h>

int sort(int temp[], int n, int bt[])
{
	int i, minx = 65000, ret=0;

	for(i=0; i<n; i++)
	{
		if(temp[i] == -1)
			break;
		if(bt[temp[i]]<minx)
		{
			minx = bt[temp[i]];
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

int ip()
{
	int n;
	scanf("%d",&n);
	return n;
}

int main(int argc, char const *argv[])
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
		at[i] = ip();
		at2[i]=at[i];
		printf("Enter burst time:");
		bt[i] = ip();
		bt2[i]=bt[i];
	}

	int temp[n],t=0;
	for (int i = 0; i < n ; ++i)
	{
		/* code */
		temp[i]=-1;
	}

	while (1)
	{
		j=0;
		
		for (i=0;i<n;i++)
		{
			if (at[i]<=t)
			{
				temp[j]=i;
				j++;
			}
		}
		if (temp[0]==-1)
		{
			t++;
		}
		else
		{
			j=sort(temp,n,bt);
			t=t+1;
			bt[j]=bt[j]-1;
			if (bt[j]==0)
			{
				ct[j]=t;
				at[j]=65000;
			}
		}
		
		for (i=0;i<n;i++)
		{
			temp[i]=-1;
		}

		if (brk(at,n)==1)
		break;
	}

	float wt_avg=0.0,ta_avg=0.0;
	
	for (i=0;i<n;i++)
	{
		printf("For Process %d: ",i);
		printf("Arrival time: %d -",at2[i]);
		printf("burst time: %d -",bt2[i]);
		printf("completion time: %d -",ct[i]);
		
		ta[i]=ct[i]-at2[i];
		ta_avg=ta_avg+ta[i];
		
		printf("turnaround time: %d -",ta[i]);
		
		wt[i]=ta[i]-bt2[i];
		wt_avg=wt_avg+wt[i];
		
		printf("waiting time: %d \n\n",wt[i]);
	}
	printf("Average waiting time: %f\n",wt_avg/n);
	printf("Average turnaround time: %f\n",ta_avg/n);

	return 0;
}