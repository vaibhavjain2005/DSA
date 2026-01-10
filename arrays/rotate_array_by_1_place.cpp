#include<iostream>
#include<vector>
using namespace std;
void rotate_by_1_place(vector<int>&nums){
    int temp=nums[0];
    int n=nums.size();
    for(int i=1;i<n-1;i++){
        nums[i-1]=nums[i];
    }
    nums[n-1]=temp;
}
int main(){
    int n;
    vector<int> nums;
    while(true){
        cin>>n;
        if(n==-1) break;
        nums.emplace_back(n);

    }
    rotate_by_1_place(nums);
    for(auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}
