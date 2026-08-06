#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& memo) {
    if(i == j) return 0;
    if(memo[i][j]!=-1)return memo[i][j];
    int minCost = INT_MAX;
    for(int k = i;k<j;k++)
    {
        int total = solve(arr,i,k,memo) + solve(arr,k+1,j,memo) + arr[i-1] * arr[k] * arr[j];
        minCost = min(minCost,total);
    }
    return memo[i][j] = minCost;
    }

    int matrixChainOrder(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(arr, 1, n - 1, memo);
    }

    int matrixChainOrderDp(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0;i<n;i++)
        {
            dp[i][i] = 0;
        }
        for(int i = n-1;i>=1;i--)
        {
            for(int j = i+1;j<n;j++)
            {
               int mini = 1e9;
               for(int k = i;k<j;k++)
               {
                int total = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini,total);
               }
               dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};
int main() {
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30};
    cout << "Minimum number of multiplications using Memo : " << sol.matrixChainOrder(arr) << endl;
    cout << "Minimum number of multiplications using Tabulation: " << sol.matrixChainOrderDp(arr) << endl;

    return 0;
}
