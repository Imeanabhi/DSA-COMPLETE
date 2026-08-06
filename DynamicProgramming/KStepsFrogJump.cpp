#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// FIXED: All methods are now grouped inside ONE single class
class FrogJumpK {
private:
    // 1. Pure Recursion Helper
    int solveRecursion(int ind, const vector<int>& heights, int k) {
        if (ind == 0) return 0;

        int minSteps = INT_MAX;

        // Try all possible jumps from 1 to K
        for (int j = 1; j <= k; ++j) {
            if (ind - j >= 0) {
                int jump = solveRecursion(ind - j, heights, k) + abs(heights[ind] - heights[ind - j]);
                minSteps = min(minSteps, jump);
            }
        }
        return minSteps;
    }

    // 2. Memoization Helper
    int solveMemo(int ind, const vector<int>& heights, int k, vector<int>& memo) {
        if (ind == 0) return 0;
        if (memo[ind] != -1) return memo[ind];

        int minSteps = INT_MAX;

        for (int j = 1; j <= k; ++j) {
            if (ind - j >= 0) {
                int jump = solveMemo(ind - j, heights, k, memo) + abs(heights[ind] - heights[ind - j]);
                minSteps = min(minSteps, jump);
            }
        }
        return memo[ind] = minSteps;
    }

public:
    int minEnergyRecursion(int n, const vector<int>& heights, int k) {
        return solveRecursion(n - 1, heights, k);
    }

    int minEnergyMemo(int n, const vector<int>& heights, int k) {
        vector<int> memo(n, -1);
        return solveMemo(n - 1, heights, k, memo);
    }

    // 3. Bottom-Up DP Table Method
    int minEnergyTable(int n, const vector<int>& heights, int k) {
        if (n <= 1) return 0;

        vector<int> dp(n, 0);
        dp[0] = 0;

        for (int i = 1; i < n; ++i) {
            int minSteps = INT_MAX;

            // Check previous K states
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    minSteps = min(minSteps, jump);
                }
            }
            dp[i] = minSteps;
        }
        return dp[n - 1];
    }
};

int main() {
    FrogJumpK solver;

    // Example heights array
    vector<int> heights = {10, 30, 40, 50, 20};
    int n = heights.size();
    int k = 3; // Frog can jump up to 3 steps at once

    cout << "--- Frog Jump with K Steps (K = " << k << ") ---\n\n";
    cout << "1. Recursion Approach:       " << solver.minEnergyRecursion(n, heights, k) << " units\n";
    cout << "2. Memoization Approach:     " << solver.minEnergyMemo(n, heights, k) << " units\n";
    cout << "3. DP Table Approach:        " << solver.minEnergyTable(n, heights, k) << " units\n";
    
    return 0;
}