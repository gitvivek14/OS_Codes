#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 30
int main(){
	int i , j , n , t, p[max],bt[max],wt[max],tat[max];
	float awt =0 , atat =0;
	system("clear");
	
	printf("Enter the number of processes");
	scanf("%d",&n);
	printf("Enter the Process number");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&p[i]);
	}
	printf("Enter the Burst time of Process");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&bt[i]);
	}
	// sort process according to burst time
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(bt[j]>bt[j+1]){
				t = bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;

				// sorting process numbers
				t = p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
	printf("process \t burst time \t waiting time \t turn around time \n");
	for (int i = 0; i < n; ++i)
	{
		wt[i]=0;
		tat[i]=0;
		for (int j = 0; j < i; ++j)
		{
			wt[i]=wt[i]+bt[j];

		}
		tat[i] = wt[i]+bt[i];
		awt = awt+wt[i];
		atat = atat+tat[i];

		printf("%d\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);

	}
	awt = awt/n;
	atat = atat/n;
    printf("average waiting time %f\n",awt);
    printf("average turn around time %f\n",atat);
    getch();
    return 0;


}