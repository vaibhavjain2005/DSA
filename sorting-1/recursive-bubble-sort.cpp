#include<iostream>
#include<vector>
using namespace std;
void recursive_bubble_sort(vector<int>& v, int n,int pos){
    if(pos>=n-1) return;
    int temp;
    for(auto it=v.begin();it!=v.end()-pos-1;it++){
        if(*(it)>*(it+1)){
        temp=*(it);
        *(it)=*(it+1);
        *(it+1)=temp;
    }
}
    pos++;
    recursive_bubble_sort(v,n,pos);
}


int main(){
    vector<int>v;
    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        v.emplace_back(a);
    }
    
    recursive_bubble_sort(v,n,0);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    return 0;

}