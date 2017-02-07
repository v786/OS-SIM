/****** First Come First Scheduling Non-Prepmtive ***********/
/****** B414009 - Jahangir Ali Khan ************/

#include <stdio.h>

int minx (int arrivaltime[], int n) // Function to return index of First arrivaltime
{
	int i,j,mint;

	int ind = 0;

	mint = 1000; // initialise min with high value

	for (i=0; i<n; i++)
	{
		if(arrivaltime[i] < mint)
		{
			ind = i;
			mint = arrivaltime[i];
		}
	}

	return ind;
}

int ip()
{
	int n;
	scanf("%d",&n);
	return n;
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
		arrivaltime[i] = ip();
		arrivaltime2[i]=arrivaltime[i];
	}

	for (i=0;i<n;i++)
	{
		printf("Enter burst time of process %d:",i);
		bursttime[i] = ip();
	}

	for (i=0;i<n;i++)
	{
		j=minx(arrivaltime,n);
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

	float wait_time_avg=0.0, turn_around_time_avg=0.0;

	for (i=0;i<n;i++)
	{
		printf("\nFor Process %d:\n",i);
		printf("Arrival time: %d ,",arrivaltime2[i]);
		printf("burst time: %d ,",bursttime[i]);
		printf("completion time: %d ,",completion_time[i]);
		turn_around_time[i]=completion_time[i]-arrivaltime2[i];
		turn_around_time_avg=turn_around_time_avg+turn_around_time[i];
		printf("turnaround time: %d ,",turn_around_time[i]);
		wait_time[i]=turn_around_time[i]-bursttime[i];
		wait_time_avg=wait_time_avg+wait_time[i];
		printf("waiting time: %d .",wait_time[i]);
	}

	printf("\nAverage waiting time: %f\n",wait_time_avg/n);
	printf("\nAverage turnaround time: %f\n",turn_around_time_avg/n);

	return 0;
}