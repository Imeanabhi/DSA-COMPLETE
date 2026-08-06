#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the length of the Longest Common Subsequence (LCS)
    int recursion(int i, int j, string& s1, string& s2, vector<vector<int>>& memo) {
        if(i < 0 || j < 0) return 0;
        
        // Return precomputed value if it exists
        if(memo[i][j] != -1) return memo[i][j];
        
        // ERROR 1 & 2 FIXED: Add 1 instead of 2, and save the result to memo[i][j]
        if(s1[i] == s2[j]) {
            return memo[i][j] = 1 + recursion(i - 1, j - 1, s1, s2, memo);
        }
        
        // ERROR 1 FIXED: Save the result of the max function to memo[i][j]
        return memo[i][j] = max(recursion(i - 1, j, s1, s2, memo), recursion(i, j - 1, s1, s2, memo));
    }
    
    int minOperations(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        int len = recursion(m - 1, n - 1, s1, s2, memo);

        return (s1.size() - len) + (s2.size() - len); 
    }
};

int main() {
    // Instantiate the Solution class
    Solution sol;

    // Test Case 1
    string s1 = "heap";
    string s2 = "pea";
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n";
    cout << "Minimum operations: " << sol.minOperations(s1, s2) << "\n\n";

    // Test Case 2
    string s3 = "sea";
    string s4 = "eat";
    cout << "Input: s1 = \"" << s3 << "\", s2 = \"" << s4 << "\"\n";
    cout << "Minimum operations: " << sol.minOperations(s3, s4) << "\n";

    return 0;
}