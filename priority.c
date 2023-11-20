#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 30
void main(){
	int n , i ,j ,t,bt[max],wt[max],pr[max],tat[max],pos;
	float awt=0,atat=0;
	system("cls");
	printf("Enter Number of Process");
	scanf("%d",&n);
	printf("Enter Burst Time of Process");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&bt[i]);
		
	}
	printf("Enter Priority of Process");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&pr[i]);
		
	}
	for (int i = 0; i < n; ++i)
	{
		pos=i;
		for(j=0;j<n;j++){
			if(pr[j]<pr[pos]){
				pos=j;
			}
		}
		t=pr[i];
		pr[i]=pr[pos];
		pr[pos]=t;

		t=bt[i];
		bt[i]=bt[pos];
		bt[pos]=t;
	}
	wt[0]=0;
	printf("process\tburst time\tpriority\twaiting time\tturn around time\n");
	for(i=0;i<n;i++){
		wt[i]=0;
		tat[i]=0;
		for(j=0;j<i;j++){
			wt[i]=wt[i]+bt[j];
		}
		tat[i]=wt[i]+bt[i];
		awt=awt+wt[i];
		atat=atat+tat[i];
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],pr[i],wt[i],tat[i]);

	}
	awt = awt/n;
	atat = atat/n;
    printf("average waiting time %f\n",awt);
    printf("average turn around time %f\n",atat);
    getch(); 

}