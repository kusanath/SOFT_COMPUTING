/*given the list of processes , their CPU burst times, display the Gantt chart for Round Robin scheduling policy ,compute and print the average waiting time and average turnaround time.*/

#include<stdio.h>
int main()
{
    int i, limit, total=0, x, counter=0, time_quantum, wait_time=0, turnaround_time=0, arrival_time[20], burst_time[20], temp[20],y,j,z,l,a;
    float average_wait_time, average_turnaround_time;
    printf("Round Robin Scheduling\n");
    printf("Enter Number of processes:");
    scanf("%d",&limit);
    x=limit;
    for(i=0; i < limit; i++)
    {
        printf("Enter CPU burst time of P[%d]:",i+1);
        scanf("%d",&burst_time[i]);
        arrival_time[i]=0;
        temp[i]=burst_time[i];
    }
    printf("Enter the time slice:");
    scanf("%d",&time_quantum);
    
    printf("\nprocess No\tBurst Time\t Waiting Time\tTurnaround Time\n");
    for(total=0, i=0; x!=0;)
    {
        if(temp[i]<= time_quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i]>0)
        {
            temp[i]=temp[i]-time_quantum;
            total=total+time_quantum;
        }
        if(temp[i]==0 && counter ==1)
        {
            x--;
            printf("\nP[%d]\t\t%d\t\t\t%d\t\t%d",i+1, burst_time[i], total-arrival_time[i]- burst_time[i], total-arrival_time[i]);
            wait_time=wait_time + total - arrival_time[i] - burst_time[i];
            turnaround_time = turnaround_time + total - arrival_time[i];
             y=total-arrival_time[i];
            counter = 0;
        }
        if(i==limit-1)
        {
            i=0;
        
        }
        else if(arrival_time[i+1] <= total)
        {
            i++;
        }
        else
        {
            i=0;
        }
        
    }
    average_wait_time = wait_time*1.0/limit;
    average_turnaround_time=turnaround_time*1.0/limit;
    printf("\nAverage waiting time=%.2f",average_wait_time);
    printf("\nAverage turnaround time=%.2f",average_turnaround_time);
    printf("\n===GANTTCHART===\n");
    for(i=0; i<y; i++)
    {
        printf("%d\t",i+1);
    }
    printf("\n");
    
    
    for(i=0; i<limit; i++)
    {
        if(burst_time[i]==0)
        {
            if(i==limit-1)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        
        j=burst_time[i];
        while(j<=time_quantum && j!=0)
        {
            printf("P[%d]\t",i+1);
            j=j-1;
            burst_time[i]=j;
        }
        if(j>time_quantum)
        {
            j=j-time_quantum;
            burst_time[i]=j;
            for(z=0; z<time_quantum; z++)
            {
                printf("P[%d]\t",i+1);
            }
            
            
        }
        if (i==(limit-1))
        {
            i=-1;
        }
        
        
        
    }
    
    return 0;
    
    
}
