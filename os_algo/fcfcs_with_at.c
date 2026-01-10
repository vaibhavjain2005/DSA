#include<stdio.h>
#define max 30
int main(){
    int n,bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];

        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t%d\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("Avg waiting time %f",awt/n);
    printf("Avg TAT %f",atat/n);
    return 0;
}