#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int count = 0;

        unordered_map<int, int> freq;

        while (i < n) {

            freq[nums[i]]++;

            while (freq.size() > k) {

                freq[nums[j]]--;

                if (freq[nums[j]] == 0) {
                    freq.erase(nums[j]);
                }

                j++;
            }

            count += i - j + 1;

            i++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

int main(){
    vector<int> arr = {1,2,1,2,3};
    int k = 2;
    Solution s;
    cout<<"The result is : "<<s.subarraysWithKDistinct(arr , k);

    return 0;
}