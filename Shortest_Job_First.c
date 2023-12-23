#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
     int temp=*a;
     *a=*b;
     *b=temp;       
}
int main()
{
     int pid[20], at[20],bt[20],ct[20],tat[20],wt[20],rt[20],i,j,n;
     printf("Enter the number of processes:");
     scanf("%d",&n);
     int c=0;
     float avg_tat=0;
     int tot_tat=0;
     int tot_wt=0;
     float avg_wt=0;
     for(i=0;i<n;i++)
     {
          printf("Enter the arrival time of process %d:",i+1);
          scanf("%d",&at[i]);
          printf("Enter the burst time of process %d:",i+1);
          scanf("%d",&bt[i]);
          pid[i]=++c;
     }
     printf("Input table:\n");
     printf("pid\tat\tbt\n");
     for(i=0;i<n;i++)
          printf("%d\t%d\t%d\n",pid[i],at[i],bt[i]);
     for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(at[i]>at[j])
               {
                    swap(&at[i],&at[j]);
                    swap(&bt[i],&bt[j]);
                    swap(&pid[i],&pid[j]);
               }
               if(at[i]==at[j])
               {
                    if(bt[i]>bt[j])
                    {
                         swap(&at[i],&at[j]);
                         swap(&bt[i],&bt[j]);
                         swap(&pid[i],&pid[j]);
                    }
               }
          }
     }
     printf("after sorting:\n");
     printf("pid\tat\tbt\n");
     for(i=0;i<n;i++)
          printf("%d\t%d\t%d\n",pid[i],at[i],bt[i]);
     ct[0]=at[0]+bt[0];
     int newct=ct[0];
     int min=1000;
     int pos;
     for(i=1;i<n;i++)
     {
          for(j=i;j<n;j++)
          {
               if(at[j]<=newct)
               {
                    if(bt[j]<min)
                    {
                         min=bt[j];
                         pos=j;
                    }
               }
          }
          if(min==1000)
          {
               newct++;
               i--;
          }
          else
          {
               swap(&at[i],&at[pos]);
               swap(&bt[i],&bt[pos]);
               swap(&pid[i],&pid[pos]);
               min=1000;
               ct[i]=newct+bt[i];
               newct=ct[i];
          }
     }
     for(i=0;i<n;i++)
     {
          tat[i]=ct[i]-at[i];
          wt[i]=tat[i]-bt[i];
          rt[i]=wt[i];   
     }
     for(i=0;i<n;i++)
     {
          tot_tat+=tat[i];
          tot_wt+=wt[i];
     }
     avg_tat=(float)tot_tat/n;
     avg_tat=(float)tot_wt/n;
     printf("Result\n");
     printf("pid\tat\tbt\tct\ttat\twt\trt\n");
     for(i=0;i<n;i++)
          printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
     printf("Average TAT=%f\n",avg_tat);
     printf("Average WT=%f\n",avg_wt);       
}
