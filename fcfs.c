/****** First Come First Scheduling Non-Prepmtive ***********/
/****** B414009 - Jahangir Ali Khan ************/

#include <stdio.h>

int minx (int arrivaltime[], int n) // Function to return index of First arrivaltime
{
	int i,j,minx;

	int ind = 0;

	minx = 1000; // initialise min with high value

	for (i=0; i<n; i++)
	{
		if(arrivaltime[i] < minx)
		{
			ind = i;
			minx = arrivaltime[i];
		}
	}

	return ind;
}

int main()
{

	printf("Enter number of processes:\n");
	int n;
	scanf("%d",&n);
	int arrivaltime[n],bursttime[n],completion_time[n],arrivaltime2[n],wait_time[n],turn_around_time[n];
	int t=0;
	int i,j;

	for (i=0;i<n;i++)
	{
		printf("Enter arrival time of process %d:",i);
		scanf("%d",&arrivaltime[i]);
		arrivaltime2[i]=arrivaltime[i];
	}

	for (i=0;i<n;i++)
	{
		printf("Enter burst time of process %d:",i);
		scanf("%d",&bursttime[i]);
	}

	for (i=0;i<n;i++)
	{
		j=ind(arrivaltime,n);
		if (arrivaltime[j]>t)
		{
			t=arrivaltime[j]+bursttime[j];
		}
		else
		{
			t=t+bursttime[j];
		}
		completion_time[j]=t;
		arrivaltime[j]=5000;
	}

	float arrivaltime wait_time_avg=0.0,turn_around_time_avg=0.0;

	for (i=0;i<n;i++)
	{
		printf("For Process %d:\n",i);
		printf("Arrival time: %d\n",arrivaltime2[i]);
		printf("burst time: %d\n",bursttime[i]);
		printf("completion time: %d\n",completion_time[i]);
		turn_around_time[i]=completion_time[i]-arrivaltime2[i];
		turn_around_time_avg=turn_around_time_avg+turn_around_time[i];
		printf("turnaround time: %d\n",turn_around_time[i]);
		wait_time[i]=turn_around_time[i]-bursttime[i];
		wait_time_avg=wait_time_avg+wait_time[i];
		printf("waiting time: %d\n",wait_time[i]);
	}

	printf("Average waiting time: %f\n",wait_time_avg/n);
	printf("Average turnaround time: %f\n",turn_around_time_avg/n);

	return 0;
}