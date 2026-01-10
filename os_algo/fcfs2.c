#include<stdio.h>

struct process{
    int pid;
    int bt;
    int at;
    int tat;
    int wt;
    int ct;
};

int main(){
    int n;
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].pid);
        scanf("%d",&p[i].bt);
        scanf("%d",&p[i].at);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                struct process t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    printf("PID\t AT \t BT \t CT \t TAT \t WT\n");
    int time=0;   
    for(int i=0;i<n;i++){
        if(time<p[i].at){
            time=p[i].at;
        }
        time+=p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        printf("%d\t %d \t %d \t %d \t %d \t %d \n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    for(int i=0;i<n;i++){
        printf("| %d \t",p[i].pid);
    }
    printf(" |\n");
    for(int i=0;i<n;i++){
        printf("%d   \t",p[i].ct);
    }

    return 0;

}