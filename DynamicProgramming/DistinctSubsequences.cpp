#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. TOP-DOWN MEMOIZATION (O(m*n) Time, O(m*n) Space)
    double memoHelper(int i, int j, string &s, string &t, vector<vector<double>> &memo) {
        if (j < 0) return 1; 
        if (i < 0) return 0; 
        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == t[j]) {
            return memo[i][j] = memoHelper(i - 1, j - 1, s, t, memo) + memoHelper(i - 1, j, s, t, memo);
        } else {
            return memo[i][j] = memoHelper(i - 1, j, s, t, memo);
        }
    }

    int numDistinctMemo(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<double>> memo(m, vector<double>(n, -1));
        return (int)memoHelper(m - 1, n - 1, s, t, memo);
    }

    // 2. BOTTOM-UP TABULATION 2D (O(m*n) Time, O(m*n) Space)
    int numDistinctTab2D(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));
        
        for (int i = 0; i <= m; i++) dp[i][0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return (int)dp[m][n];
    }

    // 3. MEMORY OPTIMIZED TABULATION (O(m*n) Time, O(n) Space using prev and curr)
    int numDistinctTabPrevCurr(string s, string t) {
        int m = s.size(), n = t.size();
        
        // We use double to prevent intermediate runtime overflows
        vector<double> prev(n + 1, 0);
        vector<double> curr(n + 1, 0);
        
        // Base case: Empty string t can always be formed 1 way
        prev[0] = 1;
        curr[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    // Depends on previous row diagonal (prev[j-1]) + previous row above (prev[j])
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[n];
    }
};

int main() {
    Solution sol;
    string s = "babgbag";
    string t = "bag";

    cout << "--- Solving for s: \"" << s << "\", t: \"" << t << "\" ---" << endl;
    cout << "Memoization:          " << sol.numDistinctMemo(s, t) << endl;
    cout << "Tabulation 2D:        " << sol.numDistinctTab2D(s, t) << endl;
    cout << "Tabulation Prev/Curr: " << sol.numDistinctTabPrevCurr(s, t) << endl;

    return 0;
}