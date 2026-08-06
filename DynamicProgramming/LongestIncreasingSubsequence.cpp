#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int idx, int prev_idx, vector<int>& nums) {
    if(idx == nums.size()) return 0;
    int skip = solve(idx+1,prev_idx,nums);
    int nonskip = 0;
    if(nums[idx] > nums[prev_idx] || prev_idx == -1)
    {
        nonskip = 1+solve(idx+1,idx,nums);
    }
    return max(skip,nonskip);
}

int lengthOfLIS(vector<int>& nums) {
    return solve(0, -1, nums);
}


int solveMemo(int idx, int prev_idx, vector<int>& nums,vector<vector<int>>&memo) {
    if(idx == nums.size()) return 0;
    if(memo[idx][prev_idx+1]!=-1) return memo[idx][prev_idx+1];
    int skip = solveMemo(idx+1,prev_idx,nums,memo);
    int nonskip = 0;
    if(nums[idx] > nums[prev_idx] || prev_idx == -1)
    {
        nonskip = 1+solveMemo(idx+1,idx,nums,memo);
    }
    return memo[idx][prev_idx+1] = max(skip,nonskip);
}

int lengthOfLISMemo(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>memo(n,vector<int>(n+1,-1));
    return solveMemo(0, -1, nums,memo);
}
int solveDp(int idx, int prev_idx, vector<int>& nums,vector<int>dp) {
    if(nums.size() == 0) return 0;
    int maxi = 0;
    for(int i = 1;i<nums.size();i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(nums[i]>nums[j])
            {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
    
}
int lengthOfLISDp(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,1);
    int maxi = 1;
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(nums[i]>nums[j])
            {
                dp[i] = max(dp[i],1 + dp[j]);
            }
        }
        maxi = max(dp[i],maxi);
    }
    return maxi;
}
int main() {
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS for nums1: " << lengthOfLIS(nums1) << endl; 
    vector<int> nums2 = {0, 1, 2, 3};
    cout << "Length of LIS for nums2: " << lengthOfLISMemo(nums2) << endl; 
    vector<int> nums3 = {7, 7, 7, 8, 7};
    cout << "Length of LIS for nums3: " << lengthOfLISDp(nums3) << endl; 
    return 0;
}