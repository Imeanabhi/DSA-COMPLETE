#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>>& memo) {
        if (i > j) {
            return 0;
        }
        if (memo[i][j] != -1) return memo[i][j];
        
        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            int total = (cuts[j+1] - cuts[i-1]) + findMinimumCost(i, k-1, cuts, memo) + findMinimumCost(k+1, j, cuts, memo);
            mini = min(mini, total);
        }
        return memo[i][j] = mini;
    }

    int minimumCost(int n, int c, vector<int> cuts) { // Pass by value to avoid modifying the original main vector twice
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> memo(c + 1, vector<vector<int>>::value_type(c + 1, -1));
        return findMinimumCost(1, c, cuts, memo);
    }

    int minimumCostDp(int n, int c, vector<int> cuts) { // Pass by value to avoid dependency issues
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
            for (int i = c; i >= 1; i--) {
            for (int j = i; j <= c; j++) {
                int mini = INT_MAX;
                
                for (int k = i; k <= j; k++) {
                    int total = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, total);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;
    Solution sol;
    
    cout << "The minimum cost incurred using Memoization : " << sol.minimumCost(n, c, cuts) << endl;
    cout << "The minimum cost incurred using Tabulation  : " << sol.minimumCostDp(n, c, cuts) << endl;

    return 0;
}