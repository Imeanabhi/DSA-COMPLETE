#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int recursion(int i,int j,string & text1,string & text2,vector<vector<int>>&memo)
    {
        if(i<0 || j<0)return 0;
        if(memo[i][j] != -1)return memo[i][j];
        if(text1[i] == text2[j]) return 1 + recursion(i-1,j-1,text1,text2,memo);
        return max(recursion(i-1,j,text1,text2,memo),recursion(i,j-1,text1,text2,memo));
    }
    int longestCommonSubsequence(string &text1, string &text2) {
       int m = text1.size();
       int n = text2.size();
       vector<vector<int>>memo(m,vector<int>(n,-1));
       return recursion(m-1,n-1,text1,text2,memo);
    }
    int longestCommonSubsequenceDp(string& text1,string &text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];

                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    string s1 = "abcde";
    string s2 = "ace";
    Solution sol;
    cout << "LCS using Memoization : " << sol.longestCommonSubsequence(s1, s2) << endl;
    cout << "LCS using Tabulation : " << sol.longestCommonSubsequenceDp(s1, s2) << endl;
    return 0;
}
