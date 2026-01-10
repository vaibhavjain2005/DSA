#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int *a,int *b){
    int swap=*a;
    *a=*b;
    *b=swap;
}
void reverse_an_array(int *a,int n,int i=0){
    if(n/2<=i){
        return;
    }
    swap(&a[i],&a[n-i-1]);
    reverse_an_array(a,n,i+1);
}
int main(){
    int n;
    cin>>n;
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    reverse_an_array(a,5);
    for(size_t i=0;i<5;i++){
        cout<<a[i];
    }
    return 0;
}