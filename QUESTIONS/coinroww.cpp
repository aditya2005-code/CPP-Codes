#include<iostream>
#include<vector>
using namespace std;
int res = 0;

void dfs(vector<int> nums , int idx , int sum){
    if(idx > nums.size() -1){
        res = max(res , sum);
        return;
    }
    dfs(nums,idx+2,sum+nums[idx]);
    dfs(nums,idx+1,sum);
}
int main(){
    int n;
    cout <<"Enter the value of n : ";
    cin >> n;

    vector<int> nums(n);

    cout<<"Enter the value in nums";

    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    dfs(nums,0,0);
    cout << res;
    return 0;
}