#include<iostream>
#include<vector>
using namespace std;

vector<int> secondLargest(vector<int>&a){
    int largest=a[0];
    int sl=INT_MAX;
    for(int i=0;i<a.size();i++){
        if(largest<a[i]){
            sl=largest;
            largest=a[i];
        }
        else if(largest>a[i] && a[i]>sl){
            sl=a[i];
        }
    }
    return {largest,sl};
}
vector<int> secondSmallest(vector<int>&a){
    int smallest=a[0];
    int ss=INT_MAX;
    for(int i=0;i<a.size();i++){
        if(smallest>a[i]){
            ss=smallest;
            smallest=a[i];
        }
        else if(smallest!=a[i] && a[i]<ss){
            ss=a[i];
        }
    }
    return {smallest,ss};
}
int main(){
    vector<int>a;
    int n;
    cout<<"Enter the Value: "<<" ";
    while(true){
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        a.emplace_back(n);
    }
    vector<int>b=secondLargest(a);
    vector<int>c=secondSmallest(a);
    cout<<"Largest Element:"<<b[0]<<" Second Largest: "<<b[1]<<" Smallest Element: "<<c[0]<<" Second Smallest: "<<c[1];
    return 0;
}