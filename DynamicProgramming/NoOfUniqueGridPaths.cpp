#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursion(int row,int col)
    {
        if(row == 0 && col == 0)
        {
            return 1;
        }
        if(row<0 || col < 0)
        {
            return 0;
        }
        return recursion(row-1,col) + recursion(row,col-1);
    }

    int recursionMemo(int row,int col,vector<vector<int>>&memo)
    {
        if(row == 0 && col == 0)
        {
            return 1;
        }
        if(row<0 || col < 0)
        {
            return 0;
        }
        return memo[row][col] = recursionMemo(row-1,col,memo) + recursionMemo(row,col-1,memo);
    }

    
    int recursionDp(int row,int col,vector<vector<int>>&dp)
    {
        for(int i = 0;i<=row;i++)
        {
            for(int j = 0;j<=col;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int down = 0;
                int right = 0;
                if(i>0)
                {
                    down = dp[i-1][j];
                }
                if(j>0)
                {
                    right = dp[i][j-1];
                }
                dp[i][j] = down + right;
            }
        }
        return dp[row][col];
    }
public:
    /*Function to count the total ways
    to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n) {
        return recursion(m-1,n-1);
    }

        int uniquePathsMemo(int m, int n) {
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return recursionMemo(m-1,n-1,memo);
    }

        int uniquePathsDp(int m, int n) {
        vector<vector<int>>Dp(m,vector<int>(n,0));
        return recursionDp(m-1,n-1,Dp);
    }
};
int main() {
    int m = 3;
    int n = 2;
    
    //Create an instance of Solution class
    Solution sol;
    
    // Call the countWays function and print the result.
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;
    cout << "Number of ways: " << sol.uniquePathsMemo(m, n) << endl;
    cout << "Number of ways: " << sol.uniquePathsDp(m, n) << endl;



    return 0;
}
