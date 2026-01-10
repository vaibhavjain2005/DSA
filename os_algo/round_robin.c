#include<stdio.h>

struct process{
    int pid;
    int bt;
    int at;
    int tat;
    int wt;
    int ct;
    int rt;
};

int main(){
    int n;
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        scanf("%d",&p[i].bt);
        scanf("%d",&p[i].at);
        p[i].rt=p[i].bt;
    }
    int tq;
    scanf("%d",&tq);
   printf("PID\t AT \t BT \t CT \t TAT \t WT\n");
    int time=0,completed=0,queue_empty=0;   
    while(completed<n){
        queue_empty=1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].rt>0){
                queue_empty=0;
                if(tq<p[i].rt){
                    p[i].rt-=tq;
                    time+=tq;
                }
                else{
                    time+=p[i].rt;
                    p[i].rt=0;
                    p[i].ct=time;
                    completed++;
                    p[i].tat=p[i].ct-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;
                    //completed++;
                }
            }

        }
        if(queue_empty==1){
            time++;
        }

    }
       
    for(int i=0;i<n;i++){
              printf("%d\t %d \t %d \t %d \t %d \t %d \n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    }
return 0;

}