#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================================================================
// 1. PURE RECURSION (Time: Exponential, Space: O(M+N) call stack)
// ============================================================================
bool wildcardRec(int i, int j, const string& s, const string& p) {
    // Base Case 1: Both string and pattern are exhausted
    if (i < 0 && j < 0) return true;
    // Base Case 2: Pattern is exhausted but string still has characters
    if (j < 0 && i >= 0) return false;
    // Base Case 3: String is exhausted but pattern has characters left
    if (i < 0 && j >= 0) {
        // Remaining pattern must only be '*' to match an empty string
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }

    // If characters match, or pattern has '?', move diagonally backward
    if (s[i] == p[j] || p[j] == '?') {
        return wildcardRec(i - 1, j - 1, s, p);
    }
    if (p[j] == '*') {
        return wildcardRec(i, j - 1, s, p) || wildcardRec(i - 1, j, s, p);
    }

    return false;
}

// ============================================================================
// 2. MEMOIZATION / TOP-DOWN (Time: O(M*N), Space: O(M*N) + O(M+N) call stack)
// ============================================================================
bool isAllStars(string& p, int n) {
    for(int i = 0; i <= n; i++) {
        if(p[i] != '*') {
            return false;
        }
    }
    return true;
}

bool wildcardMem(int i, int j, string& s, string& p, vector<vector<int>>& memo) {
    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >= 0) {
        return isAllStars(p, j);
    }
    
    if(memo[i][j] != -1) return memo[i][j];
    
    if(s[i] == p[j] || p[j] == '?') {
        return memo[i][j] = wildcardMem(i - 1, j - 1, s, p, memo);
    }
    if(p[j] == '*') {
        return memo[i][j] = wildcardMem(i - 1, j, s, p, memo) || wildcardMem(i, j - 1, s, p, memo);
    }
    return memo[i][j] = false;
}

// ============================================================================
// 3. TABULATION / BOTTOM-UP (Time: O(M*N), Space: O(M*N))
// ============================================================================
bool wildcardTab(string s, string p) {
    int m = s.length();
    int n = p.length();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;

    // Base Case 2: Pattern matching empty string (only if all characters are '*')
    // Corrected: bounds should go up to n (pattern length)
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = true;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
}

// ============================================================================
// 4. SPACE OPTIMIZATION (Time: O(M*N), Space: O(N) - uses 2 rows)
// ============================================================================
bool wildcardOpt(string s, string p) {
    int m = s.length();
    int n = p.length();

    // Corrected: Both vectors track columns (pattern dimension of size n + 1)
    vector<bool> prev(n + 1, false);
    vector<bool> curr(n + 1, false);

    // Initialize base case for empty string matching components of pattern
    prev[0] = true;
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            prev[j] = prev[j - 1];
        }
    }

    // Corrected: loops synchronized with grid limits
    for (int i = 1; i <= m; i++) {
        // A non-empty string cannot match an empty pattern
        curr[0] = false; 
        
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                curr[j] = prev[j - 1];
            } else if (p[j - 1] == '*') {
                curr[j] = curr[j - 1] || prev[j];
            } else {
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[n];
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    string s = "abcde";
    string p = "a*d?";

    int m = s.length();
    int n = p.length();

    cout << "String:  " << s << "\n";
    cout << "Pattern: " << p << "\n\n";

    cout << boolalpha;

    // 1. Pure Recursion
    bool ansRec = wildcardRec(m - 1, n - 1, s, p);
    cout << "1. Pure Recursion Answer     : " << ansRec << endl;

    // 2. Memoization
    vector<vector<int>> memo(m, vector<int>(n, -1));
    bool ansMem = wildcardMem(m - 1, n - 1, s, p, memo);
    cout << "2. Memoization Answer        : " << ansMem << endl;

    // 3. Tabulation
    bool ansTab = wildcardTab(s, p);
    cout << "3. Tabulation Answer         : " << ansTab << endl;

    // 4. Space Optimization
    bool ansOpt = wildcardOpt(s, p);
    cout << "4. Space Optimization Answer : " << ansOpt << endl;

    return 0;
}