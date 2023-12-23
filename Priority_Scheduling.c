#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct process
{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int rt;
	int wt;
	int start_time;
	int pr;
}ps[100];
int main()
{	
	int i,n;
	int completed=0;
	int current_time=0;
     int is_completed[100]={0};
     float sum_tat=0,sum_rt=0,sum_wt=0;
	printf("Enter the number the processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the arrival time of process %d ",i+1);
		scanf("%d",&ps[i].at);
		printf("Enter the burst time of process %d ",i+1);
		scanf("%d",&ps[i].bt);
		printf("Enter the priority of process %d ",i+1);
		scanf("%d",&ps[i].pr);
		ps[i].pid=i+1;
	}
	while(completed!=n)
	{
		int idex = -1;
		int maximum = INT_MAX;
		for(i=0;i<n;i++)
		{
			if(ps[i].at<=current_time&&is_completed[i]==0)
			{
				if(ps[i].pr<maximum)
				{
					maximum = ps[i].pr;
					idex=i;
				}
				else if(ps[i].pr == maximum)
				{
					if(ps[i].at<ps[idex].at)
					{
						maximum=ps[i].pr;
						idex=i;
					}
				}
			}
		}
		if(idex==-1)
			current_time++;
		else
		{
			ps[idex].start_time=current_time;
			ps[idex].ct=ps[idex].start_time+ps[idex].bt;
		     ps[idex].tat=ps[idex].ct-ps[idex].at;
			ps[idex].wt=ps[idex].tat-ps[idex].bt;
			ps[idex].rt=ps[idex].wt;
			sum_tat+=ps[idex].tat;
			sum_wt+=ps[idex].wt;
			sum_rt+=ps[idex].rt;
			completed=completed+1;
			is_completed[idex]=1;
			current_time=ps[idex].ct;
		}
	}
	printf("Process\tAT\tBT\tPt\tST\tCT\tTAT\tWT\tRT\n");
	for(i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].pr,ps[i].start_time,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
	printf("\n");
     printf("Average TAT : %f\n",(float)sum_tat/n);
	printf("Average WT : %f\n",(float)sum_wt/n);
	return 0;
}
