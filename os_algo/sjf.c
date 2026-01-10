#include<stdio.h>
#include<conio.h>
# define max 30

void main(){
    int n,t,p[max],bt[max],wt[max],tat[max];
    float awt=0;,atat=0;
    printf("Enter the no. of processes");
    scanf("%d",&n);
    printf("Enter the process number");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the burst time of the process");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                //swap
                int temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                //swap process number
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("process \t burst time \t waiting time \t turn around time\n");   
    for(int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++){
            wt[i]+=bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt +=wt[i];
        atat+=tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    awt/=n;
    atat/=n;
    printf("Average waiting time is %f\n",awt);
    printf("Average turn around time is %f\n",atat);
    return 0;
}