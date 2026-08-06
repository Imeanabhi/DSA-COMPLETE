#include <bits/stdc++.h>
using namespace std;
int memoizationSolve(int i, int j, string &s, vector<vector<int>> &memo) {
    if(i>j) return 0;
    if(i == j)return 1;
    if (memo[i][j] != -1) return memo[i][j];
    if(s[i] == s[j])
    {
        return memo[i][j] =  2 + memoizationSolve(i+1,j-1,s,memo);
    }
    return memo[i][j] = max(memoizationSolve(i + 1, j, s, memo), 
                            memoizationSolve(i, j - 1, s, memo));
}

int main() {
    string s = "abccbaa";
    int n = s.size();
    cout << "Analyzing input string: \"" << s << "\"\n";
    cout << "--------------------------------------\n";
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int memoResult = memoizationSolve(0, n - 1, s, memo);
    cout << "1. Memoization (Top-Down) Length : " << memoResult << endl;

    string t = s;
    reverse(t.begin(), t.end()); // LPS = LCS(s, reverse(s))
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << "2. Tabulation (Bottom-Up) Length : " << dp[n][n] << endl;

    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            } else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    cout << "3. Space-Optimized 1D DP Length  : " << prev[n] << endl;
    int r = n, c = n;
    string lpsString = "";
    while (r > 0 && c > 0) {
        if (s[r - 1] == t[c - 1]) {
            lpsString.push_back(s[r - 1]);
            r--; 
            c--;
        } else if (dp[r - 1][c] > dp[r][c - 1]) {
            r--;
        } else {
            c--;
        }
    }
    cout << "4. Actual Printed Subsequence    : \"" << lpsString << "\"\n";
    cout << "--------------------------------------\n";
    return 0;
}