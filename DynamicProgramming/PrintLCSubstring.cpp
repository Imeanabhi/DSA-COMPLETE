#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string LCSubstring(string &text1, string &text2) { 
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
        int max_i = 0;
        int max_j = 0;
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) { 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                        if (dp[i][j] > ans) {
                        ans = dp[i][j];
                        max_i = i;
                        max_j = j;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        if (ans == 0) return "";
        
        int i = max_i;
        int j = max_j;
        string lcs = "";
        
        while (i > 0 && j > 0 && dp[i][j] > 0) {
            lcs.push_back(text1[i - 1]);
            i--;
            j--;
        }
        
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};
int main() {
    string s1 = "abcdef";
    string s2 = "abcfed";
    Solution sol;
    string ans = sol.LCSubstring(s1, s2);
    
    cout << "The LCS is : " << ans << endl; 
    return 0;
}