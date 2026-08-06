#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    int solve(int index,vector<int>&arr,vector<int>&memo)
    {
        if(index == 0) return arr[0];
        if(index<0) return 0;
        if(memo[index]!=-1)return memo[index];
        int pick = arr[index] + solve(index-2,arr,memo);
        int nonpick = solve(index-1,arr,memo);
        return memo[index] = max(pick,nonpick);
    }
    int solveLinear(vector<int>arr)
    {
        int n = arr.size();
        vector<int>memo(n,-1);
        return solve(n-1,arr,memo);
    }
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Create two sub-arrays
        vector<int> repo1(nums.begin(), nums.end() - 1);
        vector<int> repo2(nums.begin() + 1, nums.end());

        return max(solveLinear(repo1), solveLinear(repo2));
    }
};

int main() {
    Solution solver;

    // Test Case 1: Circular street where picking house 0 and 2 is best
    // Houses: [2, 3, 2] -> Max money = 3 (Can't pick house 0 and house 2 together)
    std::vector<int> houses1 = {2, 3, 2};
    std::cout << "Test Case 1 Max Money: " << solver.rob(houses1) << " (Expected: 3)\n";

    // Test Case 2: Standard circular street sequence
    // Houses: [1, 2, 3, 1] -> Max money = 4 (Rob house 1 and house 3 -> 2 + 1 = 3 OR house 0 and house 2 -> 1 + 3 = 4)
    std::vector<int> houses2 = {1, 2, 3, 1};
    std::cout << "Test Case 2 Max Money: " << solver.rob(houses2) << " (Expected: 4)\n";

    // Test Case 3: Single house
    std::vector<int> houses3 = {5};
    std::cout << "Test Case 3 Max Money: " << solver.rob(houses3) << " (Expected: 5)\n";

    // Test Case 4: Larger street sequence
    // Houses: [20, 3, 2, 11, 5, 10] 
    // Best option: Rob 20, 11, 10 -> Total = 41
    std::vector<int> houses4 = {20, 3, 2, 11, 5, 10};
    std::cout << "Test Case 4 Max Money: " << solver.rob(houses4) << " (Expected: 41)\n";

    return 0;
}