// 4. Count Number of Pairs ⭐⭐⭐⭐⭐

// Instead of returning pair.

// nums = [1,5,7,-1,5]
// target = 6

// Answer = 3

// Need frequency map.

#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------
// Approach 1 : Brute Force
// Time : O(n^2)
// Space: O(1)
//------------------------------------------------------------
int countPairsBrute(vector<int> nums, int target)
{
    int count = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] + nums[j] == target)
                count++;
        }
    }

    return count;
}

//------------------------------------------------------------
// Approach 2 : Sorting + Two Pointers
// Time : O(n log n)
// Space: O(1)
// Correctly handles duplicates
//------------------------------------------------------------
int countPairsTwoPointers(vector<int> nums, int target)
{
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;
    long long ans = 0;

    while(left < right)
    {
        int sum = nums[left] + nums[right];

        if(sum < target)
        {
            left++;
        }
        else if(sum > target)
        {
            right--;
        }
        else
        {
            // Same numbers
            if(nums[left] == nums[right])
            {
                long long freq = right - left + 1;
                ans += freq * (freq - 1) / 2;
                break;
            }

            int leftVal = nums[left];
            int rightVal = nums[right];

            long long leftCount = 0;
            long long rightCount = 0;

            while(left <= right && nums[left] == leftVal)
            {
                leftCount++;
                left++;
            }

            while(right >= left && nums[right] == rightVal)
            {
                rightCount++;
                right--;
            }

            ans += leftCount * rightCount;
        }
    }

    return ans;
}

//------------------------------------------------------------
// Approach 3 : HashMap (Frequency Map)
// Time : O(n)
// Space: O(n)
//------------------------------------------------------------
int countPairsHashMap(vector<int> nums, int target)
{
    unordered_map<int,int> freq;

    for(int x : nums)
        freq[x]++;

    long long ans = 0;

    for(auto num : freq)
    {
        int diff = target - num.first;

        if(!freq.count(diff))
            continue;

        if(num.first == diff)
        {
            ans += 1LL * num.second * (num.second - 1) / 2;
        }
        else if(num.first < diff)
        {
            ans += 1LL * num.second * freq[diff];
        }
    }

    return ans;
}

//------------------------------------------------------------
// Driver
//------------------------------------------------------------
int main()
{
    vector<int> nums = {1,5,7,-1,5};
    int target = 6;

    cout << "Brute Force      : "
         << countPairsBrute(nums, target) << endl;

    cout << "Two Pointers     : "
         << countPairsTwoPointers(nums, target) << endl;

    cout << "HashMap          : "
         << countPairsHashMap(nums, target) << endl;

    return 0;
}