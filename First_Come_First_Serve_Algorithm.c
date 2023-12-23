#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,pid[20], arrival[20], burst[20],temp,comp[20],tat[20],wt[20],rt[20];
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int c=1;
	for(i=0;i<n;i++)
	{
		printf("\nEnter the arrival time of process %d :",i+1);
		scanf("%d",&arrival[i]);
		printf("Enter the burst time of process %d :",i+1);
		scanf("%d",&burst[i]);
		pid[i]=c;
		c++;
	}
	printf("\nThe input table is :\n");
	printf("P_id	AT	BT\n");
	for(i=0;i<n;i++)
		printf("p[%d]	%d	%d\n",pid[i], arrival[i], burst[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arrival[i]>arrival[j])
			{
				temp=arrival[i];
				arrival[i]=arrival[j];
				arrival[j]=temp;
				
				temp=burst[i];
				burst[i]=burst[j];
				burst[j]=temp;
				
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;

			}
		}
	}
	printf("\nAfter sorting the updated table is:\n");
	printf("P_id	AT	BT\n");
	for(i=0;i<n;i++)
		printf("p[%d]	%d	%d\n",pid[i], arrival[i], burst[i]);
	printf("\nAfter calculation of CT, TAT, WT and RT the updated table is :\n");
	comp[0]=burst[0];
	for(i=1;i<n;i++)
	{
		if(arrival[i]>burst[i-1])
			comp[i]=arrival[i]+burst[i];
		else
			comp[i]=comp[i-1]+burst[i];
	}
	for(i=0;i<n;i++)
		tat[i]=comp[i]-arrival[i];
	for(i=0;i<n;i++)
		wt[i]=tat[i]-burst[i];
	for(i=0;i<n;i++)
		rt[i]=wt[i];
	printf("P_id	AT	BT	CT	TAT	WT	RT\n");
	for(i=0;i<n;i++)
		printf("p[%d]	%d	%d	%d	%d	%d	%d\n",pid[i], arrival[i], burst[i], comp[i], tat[i], wt[i], rt[i]);
}
