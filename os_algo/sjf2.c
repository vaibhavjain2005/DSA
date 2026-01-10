#include<stdio.h>

struct process{
    int pid;
    int bt;
    int at;
    int tat;
    int wt;
    int ct;
    int done;
};

int main(){
    int n;
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        scanf("%d",&p[i].bt);
        scanf("%d",&p[i].at);
        p[i].done=0;
    }
   printf("PID\t AT \t BT \t CT \t TAT \t WT\n");
    int time=0,completed=0;   
    while(completed<n){
        int idx=-1,min_bt=9999;
        for(int i=0;i<n;i++){
            if(p[i].done==0 && p[i].at<=time && p[i].bt<min_bt){
                min_bt=p[i].bt;
                idx=i;
            }
        }
        if(idx==-1){
            time++;
        }
        else{
        if(time<p[idx].at){
            time=p[idx].at;
        }
        time+=p[idx].bt;
        p[idx].ct=time;
        p[idx].tat=p[idx].ct-p[idx].at;
        p[idx].wt=p[idx].tat-p[idx].bt;
        // printf("| %d \t",p[idx].pid);
        // printf(" |\n");
        // printf("%d   \t",p[idx].ct);
        completed++;
        p[idx].done=1;
    }
    }
    for(int i=0;i<n;i++){
              printf("%d\t %d \t %d \t %d \t %d \t %d \n",p[idx].pid,p[idx].at,p[idx].bt,p[idx].ct,p[idx].tat,p[idx].wt);

    }
    for(int i=0;i<n;i++){
        
    }

    return 0;

}