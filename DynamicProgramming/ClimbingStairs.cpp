#include <bits/stdc++.h>
#include <vector>
using namespace std;

class ClimbingStairs {
public:
    int climbStairsRecursion(int n)
    {
        if(n<=1) return 1;
        return climbStairsRecursion(n-1) + climbStairsRecursion(n-2);
    }
    
    int memoHelper(int n, vector<int>& memo)
    {
        if(n<=1) return 1;
        if(memo[n]!=-1) return memo[n];
        return memo[n] = memoHelper(n-1, memo) + memoHelper(n-2, memo);
    }
    
    int climbStairsMemo(int n) {
        vector<int> memo(n + 1, -1);
        return memoHelper(n, memo);
    }

    // FIXED: Added second slash to make it a proper C++ comment
    // 3. Bottom-Up DP Table
    int climbStairsTable(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    
    int climbStairsOptimized(int n) {
        if (n <= 1) return 1;
        int prev2 = 1, prev1 = 1, current = 0;
        for (int i = 2; i <= n; ++i) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

int main() {
    ClimbingStairs solver;
    int totalStairs = 5; 

    cout << "--- Climbing Stairs Solutions for " << totalStairs << " steps ---\n\n";
    cout << "1. Recursion Approach:       " 
         << solver.climbStairsRecursion(totalStairs) << " ways\n";

    cout << "2. Memoization Approach:     " 
         << solver.climbStairsMemo(totalStairs) << " ways\n";

    cout << "3. DP Table Approach:        " 
         << solver.climbStairsTable(totalStairs) << " ways\n";

    cout << "4. Space Optimized Approach: " 
         << solver.climbStairsOptimized(totalStairs) << " ways\n";

    return 0;
}