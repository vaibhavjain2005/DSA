#include<iostream>
#include<vector>

using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(size_t *arr,int n){
    // cout<<"I am called";
for(int i=0;i<=n-2;i++){
    int min=i;
    for(int j=i;j<=n-1;j++){
        if(arr[min]>arr[j]){
            min=j;
        }
        swap(arr[min],arr[i]);
    }
}
}
int main(){
    size_t n;
    cin>>n;
    size_t *arr=(size_t*)malloc(sizeof(size_t)*n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
            cout<<"Sorted Array: ";

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}