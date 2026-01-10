#include<iostream>
#include<vector>

using namespace std;

vector<int> tunion(vector<int>a,vector<int>b){
    vector<int>u;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
        if(u.size()==0 || u.back()!=a[i]){
            u.push_back(a[i]);
            
        }
        i++;
    }else{
            if(u.size()==0 || u.back()!=b[j]){
                u.push_back(b[j]);
            }
            j++;
        }
    }

        while(i<a.size()){
           if(u.back()!=a[i]){
            u.push_back(a[i]);
           }
           i++; 
        }
        while(j<b.size()){
           if(u.back()!=b[j]){
            u.push_back(b[j]);
           }
           j++; 
        }
return u;
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int>a,b;
    int d;
    for(int i=0;i<n1;i++){
        cin>>d;
        a.push_back(d);
    }
    for(int i=0;i<n2;i++){
        cin>>d;
        b.push_back(d);
    }
    vector<int>c=tunion(a,b);
    for(auto it:c){
        cout<<it<<" ";
    }
    return 0;
}