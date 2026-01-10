#include<stdio.h>
int main(){
    int allocation[10][10];
    int max[10][10];
    int need[10][10];







    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    int finish={0},flag,safe[10],k=0;
    for(int i=0;i<10;i++){
        flag=0;
        if(finish[i]==0){
            for(int j=0;j<10;j++){
                if(need[i][j]>available[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                finish[i]=1;
                    safe[k]=i;
                    k++;
                    for(int j=0;j<n;j++){
                        available[j]+=allocation[i][j];
                    }
                    i=-1;
            }
        }
        }
        flag=0;
        
    }
}