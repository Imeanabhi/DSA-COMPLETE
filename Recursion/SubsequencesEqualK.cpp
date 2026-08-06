#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to count subsequences with the target sum
    int func(int ind, int sum, vector<int> &nums) {
        if(ind == nums.size())
        {
            if(sum == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int pick = func(ind+1,sum-nums[ind],nums);
        int nonpick = func(ind+1,sum,nums);
        return pick + nonpick;
    }

public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};

int main() {
    Solution sol;
    // This will now correctly handle zeros and negative numbers as well
    vector<int> nums = {1, 2, 3, 4, 5}; 
    int target = 5;
    cout << "Number of subsequences with target sum " << target << ": "
         << sol.countSubsequenceWithTargetSum(nums, target) << endl;
    return 0;
}