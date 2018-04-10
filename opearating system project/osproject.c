#include<stdio.h>
#include<stdlib.h> 
 
int main() 
{ 
      int i;
	  int limit, total= 0, x, counter= 0, time_quantum,t; 
      int wait_time = 0, turnaround_time = 0;
      int pos,k,p[10],prior[10], arrival_time[10], burst_time[10], temp[10],s; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit); 
      if(limit<=0){
      
         printf("not a valid process number");
              printf("\n");
              	exit(0);
      }
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
          p[i]=i+1;
          prior[i]=0;
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
      if(arrival_time[i]<0){
      	
        printf("not a valid arrival time");
              printf("\n");
              	exit(0);
       }
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
      if(burst_time[i]<=0){
      	
           printf("not a valid burst time");
              printf("\n");
              	exit(0);
      }
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum);
      if(time_quantum<=0){
      	
      	 printf("not a valid time quantum");
              printf("\n");
			  	exit(0); 
       
      } 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(total = 0, i = 0; x != 0;) 
      { 

                for(k=0;k<limit;k++)
                {
                  int temp1;
                  pos=k;
                  for(t=k+1;t<limit;t++)
                  {
                      if(prior[t]<prior[pos])
                        pos=t;
                  }
             
                  temp1=prior[k];
                  prior[k]=prior[pos];
                  prior[pos]=temp1;
             
                  temp1=burst_time[k];
                  burst_time[k]=burst_time[pos];
                  burst_time[pos]=temp1;
                  
                  temp1=arrival_time[k];
                  arrival_time[k]=arrival_time[pos];
                  arrival_time[pos]=temp1;

                  temp1=p[k];
                  p[k]=p[pos];
                  p[pos]=temp1;

                  temp1=temp[k];
                  temp[k]=temp[pos];
                  temp[pos]=temp1;
                }
            
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
      for(s=0;s<limit;s++)
            {
                  if(s==i)
                  prior[s]+=1;
                  else
                  prior[s]+=2;
            }
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d\t\t\t %d", p[i], burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i],prior[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
            
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
}
