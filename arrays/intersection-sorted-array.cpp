#include<iostream>
#include<vector>

using namespace std;

vector<int> sorted intersection(vector<int>a,vector<int>b){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a)
    }
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