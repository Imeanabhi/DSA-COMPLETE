#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Changed return type to string to properly handle characters
    string LCS(string &text1, string &text2) { 
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
        
        // Step 1: Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) { 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Step 2: Reconstruct the LCS string
        int i = m;
        int j = n;
        string lcs = ""; // Use string instead of vector<int>
        
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                lcs.push_back(text1[i - 1]);
                i--;
                j--;
            } 
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } 
            else {
                j--;
            }
        }
        
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    Solution sol;
    string ans = sol.LCS(s1, s2);
    
    cout << "The LCS is : " << ans << endl;
    return 0;
}