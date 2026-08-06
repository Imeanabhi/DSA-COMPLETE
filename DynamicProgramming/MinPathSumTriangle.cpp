#include <bits/stdc++.h>
using namespace std;

// Class to solve the problem
class Solution {
public:
    // Recursive function with memoization
    int solveMemo(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &memo) {
        if (memo[i][j] != -1)return memo[i][j];
        if (i == n - 1)return triangle[i][j];
        int down = triangle[i][j] + solveMemo(i + 1, j, triangle, n, memo);
        int diag = triangle[i][j] + solveMemo(i + 1, j + 1, triangle, n, memo);
        return memo[i][j] = min(down, diag);
    }

    int minimumPathSumMemo(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solveMemo(0, 0, triangle, n, memo);
    }
    int solveDp(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                // Calculate sum from down and diagonal paths
                int up = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(up, diag);
            }
        }

        // Return the minimum path sum from top
        return dp[0][0];
    }
    int minimumPathSumDp(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return solveDp(0, 0, triangle, n, dp);
    }
};

// Main function
int main() {
    Solution obj;
    vector<vector<int>> triangle{
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    cout << obj.minimumPathSumMemo(triangle)<<endl;
    cout << obj.minimumPathSumDp(triangle)<<endl;
    return 0;
}
