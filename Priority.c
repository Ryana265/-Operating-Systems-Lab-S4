#include<stdio.h>
int main(){
    int n,i,j,t_wt,t_tat,pos,temp,total=0;
	float a_wt,a_tat;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n],procs[n],prio[n];
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++){
     printf("Burst Time:");
     scanf("%d",&bt[i]);
     printf("Priority:");
     scanf("%d",&prio[i]);
     procs[i]=i+1;          
    }
    for(i=0;i<n;i++){
    pos=i;
     for(j=i+1;j<n;j++){
        if(prio[j]<prio[pos])
         pos=j;
     }
     temp=prio[i];
     prio[i]=prio[pos];
     prio[pos]=temp;
 
     temp=bt[i];
     bt[i]=bt[pos];
     bt[pos]=temp;
 
     temp=procs[i];
     procs[i]=procs[pos];
     procs[pos]=temp;}
 
    wt[0]=0; 
    for(i=1;i<n;i++){
        wt[i]=0;
     for(j=0;j<i;j++)
        wt[i]+=bt[j];
     total += wt[i];}
 
    for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		t_tat+=tat[i];
	}
	printf("Process No\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t %d\t\t %d\t\t %d\n",procs[i],bt[i],wt[i],tat[i]);		
	}
	a_wt=(float)t_wt/n;
	a_tat=(float)t_tat/n;
	printf("\nAverage Waiting time = %.2f\n",a_wt);
	printf("Average Turn Around time = %.2f\n",a_tat);
}
