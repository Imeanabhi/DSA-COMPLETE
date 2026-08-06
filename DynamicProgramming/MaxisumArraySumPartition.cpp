#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Recursive helper function to find max sum from 'start' index
    int helper(const vector<int>& arr, int k, int start, vector<int>& memo) {
        int n = (int)arr.size();
        if (start == n) return 0;
        if (memo[start] != -1) return memo[start];
        int maxSum = 0;    
        int maxElem = 0;   
        for (int length = 1; length <= k && start + length <= n; length++) {
            maxElem = max(maxElem, arr[start + length - 1]);
            int currentSum = maxElem * length + helper(arr, k, start + length, memo);
            maxSum = max(maxSum, currentSum);
        }
        return memo[start] = maxSum;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = (int)arr.size();
        vector<int> memo(n, -1);
        return helper(arr, k, 0, memo);
    }
};
int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    Solution sol;
    cout << "Maximum sum after partitioning: " << sol.maxSumAfterPartitioning(arr, k) << "\n";
    return 0;
}
