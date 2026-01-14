#include<iostream>
#include<vector>

using namespace std;
int longest_subarray(vector<int>a,int k){
    int s=0,len=0;
    for(int i=0;i<a.size();i++){
        s=0;
        for(int j=0;j<a.size();j++){
            s+=a[j];
            if(s==k) len=max(len,j-i+1);
        }
}
return len;
}  
int main(){
   int n;
   cin>>n;
   int a,i=0;
   vector<int>ab;
   while(i<n){
    cin>>a;
    ab.push_back(a);
    i++;
   }
   int k;
   cin>>k;
   cout<<longest_subarray(ab,k);
   return 0;
}