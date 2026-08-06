#include <bits/stdc++.h>
using namespace std;

int memoizationSolve(int i, int j, string &s, vector<vector<int>> &memo) {
    if (i > j) return 0;
    if (i == j) return 1; // Base Case: Single character is a palindrome of length 1
    
    if (memo[i][j] != -1) return memo[i][j];
    
    if (s[i] == s[j]) {
        return memo[i][j] = 2 + memoizationSolve(i + 1, j - 1, s, memo);
    }
    return memo[i][j] = max(memoizationSolve(i + 1, j, s, memo), 
                            memoizationSolve(i, j - 1, s, memo));
}

int main() {
    string s = "abbcbab";
    int n = s.size();
    
    cout << "Analyzing input string: \"" << s << "\"\n";
    cout << "--------------------------------------\n";

    // ==========================================
    // METHOD 1: Top-Down Recursion with Memoization
    // ==========================================
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int memoResult = memoizationSolve(0, n - 1, s, memo);
    cout << "1. Memoization (Top-Down) Length : " << s.size() - memoResult << endl;
}