#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursion(int i, int j, vector<vector<int>>& matrix){
    if(i == 0 && j == 0)
    {
        return 1;
    }
    if(i<0 || j<0 || matrix[i][j] == 1)
    {
        return 0;
    }
    return recursion(i-1,j,matrix) + recursion(i,j-1,matrix);
}

    int recursionMemo(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&memo){
    if(i == 0 && j == 0)
    {
        return 1;
    }
    if(memo[i][j]!=-1) return memo[i][j];
    if(i<0 || j<0 || matrix[i][j] == 1)
    {
        return 0;
    }
    return memo[i][j] = recursion(i-1,j,matrix) + recursion(i,j-1,matrix);
}

int recursionDp(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>&dp){

    for(int i = 0;i<=row;i++)
    {
        for(int j = 0;j<=col;j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if(matrix[i][j] == 1)
            {
                dp[i][j] = 0;
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
            dp[i][j] = right + down;
        }
    }
    return dp[row][col];
}

public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        return recursion(m-1, n-1, matrix);
    }

    int uniquePathsWithObstaclesMemo(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return recursionMemo(m-1, n-1, matrix,memo);
    }
    int uniquePathsWithObstaclesDp(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>Dp(m,vector<int>(n,0));
        return recursionDp(m-1, n-1, matrix,Dp);
    }
};

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    Solution sol;
    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstacles(maze) << endl;
    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstaclesMemo(maze) << endl;
    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstaclesDp(maze) << endl;
    return 0;
}
