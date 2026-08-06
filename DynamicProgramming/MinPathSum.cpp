#include <bits/stdc++.h>
using namespace std;

// Class containing the solution logic
class Solution {
public:
    int recursion(int row,int col,vector<vector<int>>&grid)
    {
        if(row == 0 && col == 0)
        {
            return grid[0][0];;
        }
        if(row<0 || col<0) return 1e9;
        int up = grid[row][col] + recursion(row-1,col,grid);
        int left = grid[row][col] + recursion(row,col-1,grid);
        return min(up,left);
    }
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minsum = 0;
        return recursion(n - 1, m - 1, grid);
    }
    int recursionMemo(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&memo)
    {
        if(row == 0 && col == 0)
        {
            return grid[0][0];;
        }
        if(memo[row][col] != -1)
        {
            return memo[row][col];
        }
        if(row<0 || col<0) return 1e9;
        int up = grid[row][col] + recursion(row-1,col,grid);
        int left = grid[row][col] + recursion(row,col-1,grid);
        return memo[row][col] = min(up,left);
    }
    int minPathSumMemo(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minsum = 0;
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return recursionMemo(n - 1, m - 1, grid,memo);
    }
    int recursionDp(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(row == 0 && col == 0)
        {
            return grid[0][0];;
        }
        for(int i = 0;i<=row;i++)
        {
            for(int j = 0;j<=col;j++)
            {
                if(i == 0 && j == 0 )
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int down = INT_MAX;
                int right = INT_MAX;
                if(i>0)
                {
                    down = grid[i][j] + dp[i-1][j];
                }
                if(j>0)
                {
                    right = grid[i][j] + dp[i][j-1];
                }
                dp[i][j] = min(down,right);
            }
        }
        return dp[row][col];
    }
    int minPathSumDp(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minsum = 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        return recursionDp(n - 1, m - 1,grid,dp);
    }
};

// Driver function
int main() {
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };

    Solution obj;
    cout << "Minimum sum path: with Recursive Approach : "<< obj.minPathSum(grid) << endl;
    cout << "Minimum sum path: with Memoization Table : "<< obj.minPathSumMemo(grid) << endl;
    cout << "Minimum sum path with DP Table : "<< obj.minPathSumDp(grid) << endl;
    return 0;
}
