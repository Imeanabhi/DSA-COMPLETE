#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;

    int solveRecursion(int i, int target, vector<int>& arr) {
        if (i == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }

        int notTake = solveRecursion(i - 1, target, arr);
        int take = 0;
        if (arr[i] <= target) {
            take = solveRecursion(i - 1, target - arr[i], arr);
        }

        return notTake + take;
    }

    int solveMemoization(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int notTake = solveMemoization(i - 1, target, arr, dp);
        int take = 0;
        if (arr[i] <= target) {
            take = solveMemoization(i - 1, target - arr[i], arr, dp);
        }

        return dp[i][target] = (notTake + take) % MOD;
    }

public:
    int countPartitionsRecursion(vector<int>& arr, int d) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        if (totalSum < d || (totalSum + d) % 2 != 0) return 0;

        int target = (totalSum + d) / 2;
        int n = arr.size();
        return solveRecursion(n - 1, target, arr);
    }

    int countPartitionsMemoization(vector<int>& arr, int d) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        if (totalSum < d || (totalSum + d) % 2 != 0) return 0;

        int target = (totalSum + d) / 2;
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solveMemoization(n - 1, target, arr, dp);
    }

    int countPartitions2DTabulation(vector<int>& arr, int d) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        if (totalSum < d || (totalSum + d) % 2 != 0) return 0;

        int target = (totalSum + d) / 2;
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1; // Base case: 1 way to make sum 0 with 0 elements

        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[i - 1][t];
                int take = 0;
                if (arr[i - 1] <= t) {
                    take = dp[i - 1][t - arr[i - 1]];
                }
                dp[i][t] = (notTake + take) % MOD;
            }
        }
        return dp[n][target];
    }

    int countPartitions1DSpaceOptimized(vector<int>& arr, int d) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        if (totalSum < d || (totalSum + d) % 2 != 0) return 0;

        int target = (totalSum + d) / 2;
        int n = arr.size();

        vector<int> dp(target + 1, 0);
        dp[0] = 1; // Base case: 1 way to make sum 0 with empty set

        for (int i = 0; i < n; i++) {
            for (int t = target; t >= arr[i]; t--) {
                dp[t] = (dp[t] + dp[t - arr[i]]) % MOD;
            }
        }
        return dp[target];
    }
};

int main() {
    Solution solver;
    
    // Sample inputs
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    
    cout << "--- Counting Partitions with Given Difference ---" << endl;
    cout << "Input Array : { ";
    for(int x : arr) cout << x << " ";
    cout << "}\nDifference  : " << d << "\n\n";

    // Executing each algorithm block
    cout << "Method 1 (Recursion)       : " << solver.countPartitionsRecursion(arr, d) << endl;
    cout << "Method 2 (Memoization)     : " << solver.countPartitionsMemoization(arr, d) << endl;
    cout << "Method 3 (2D Tabulation)   : " << solver.countPartitions2DTabulation(arr, d) << endl;
    cout << "Method 4 (1D Optimized)    : " << solver.countPartitions1DSpaceOptimized(arr, d) << endl;

    return 0;
}