#include<stdio.h>
#define max 30
int main(){
    int n,bt[max],wt[max],tat[max],at[max],temp[max];
    float awt=0,atat=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    //arrival time
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    temp[0]=0;
    printf("Proceess\tburst time\tarrival time\twaiting time\tturn around time");
    for(int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];

        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
    }
    printf("Avg waiting time %f",awt/n);
    printf("Avg TAT %f",atat/n);
    return 0;
}