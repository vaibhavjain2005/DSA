#include<iostream>
#include<vector>
using namespace std;
vector<int> reorder_by_sign_variety_2(vector<int>&nums){
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            neg.emplace_back(nums[i]);
        }else{
            pos.emplace_back(nums[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            nums[i*2]=pos[i];
            nums[2*i+1]=neg[i];
        }
    int a=neg.size()*2;
    for(int i=neg.size();i<pos.size();i++){
        nums[a++]=pos[i];
    }
}
    else{
        for(int i=0;i<pos.size();i++){
            nums[i*2]=pos[i];
            nums[2*i+1]=neg[i];
        }
    int a=pos.size()*2;
    for(int i=pos.size();i<neg.size();i++){
        nums[a++]=neg[i];
    }
}
return nums;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
    nums=reorder_by_sign_variety_2(nums);
    for(auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}