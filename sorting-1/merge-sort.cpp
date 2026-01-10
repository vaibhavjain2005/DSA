#include<iostream>
using namespace std;
void merge(int low,int high,int mid,int *a,int *temp){
    int left=low;
    int right=mid+1;
    int i=low;
    while(low<=mid && right<=high){
        if(a[left]<=a[right]){
            temp[i++]=a[left];
            left++;
        } else{
            temp[i++]=a[right];
            right++;
        }
    }
    while(left<=mid){
        temp[i++]=a[left];
        left++;
    }
    while(right<=high){
        temp[i++]=a[right];
        right++;
        
    }
    //int j=low;
    for(int j=low;j<=high;j++){
        a[j]=temp[j];
    }
}
void mergesort(int low,int high,int *a,int *temp){
    if(low<high){
       int mid=(low+high)/2;
        mergesort(low,mid,a,temp);
        mergesort(mid+1,high,a,temp);
        merge(low,high,mid,a,temp);
    }
}

int main(){
    size_t n;
    cin>>n;
    int *a=(int*)malloc(sizeof(int)*n);
    int *temp=(int*)malloc(sizeof(int)*n);
    for(size_t i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(0,n-1,a,temp);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}