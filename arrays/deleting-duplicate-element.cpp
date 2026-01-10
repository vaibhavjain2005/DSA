#include<iostream>

int main(){
    vector<int>a;
    int n;
    while(true){
        scanf("%d",&n);
        if(n==-1) break;
        a.emplace_back(n);
    }
    return 0;
}