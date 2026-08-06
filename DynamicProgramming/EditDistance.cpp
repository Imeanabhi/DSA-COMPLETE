#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. PURE RECURSION (Time: O(3^(M+N)), Space: O(M+N) call stack)
// ============================================================================
int recursion(int i, int j, const string& s1, const string& s2) {
    if(i<0) return j + 1;
    if(j<0) return i + 1;
    if(s1[i] == s2[j]) return 0 + recursion(i-1,j-1,s1,s2);
    int insertS1 = 1 + recursion(i,j-1,s1,s2);
    int deleteS1 = 1 + recursion(i-1,j,s1,s2);
    int replace = 1 + recursion(i-1,j-1,s1,s2);
    return min({insertS1,deleteS1,replace});
}

// ============================================================================
// 2. MEMOIZATION / TOP-DOWN (Time: O(M*N), Space: O(M*N) + O(M+N) call stack)
// ============================================================================
int editDistanceMem(int i, int j, const string& s1, const string& s2, vector<vector<int>>& dp) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    // Return already computed result
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) {
        return dp[i][j] = editDistanceMem(i - 1, j - 1, s1, s2, dp);
    }

    int insertS1 = 1 + editDistanceMem(i, j - 1, s1, s2, dp);
    int deleteS1 = 1 + editDistanceMem(i - 1, j, s1, s2, dp);
    int replace = 1 + editDistanceMem(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = min({insertS1, deleteS1, replace});
}

// ============================================================================
// 3. TABULATION / BOTTOM-UP (Time: O(M*N), Space: O(M*N))
// ============================================================================
int editDistanceTab(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    
    // dp[i][j] stores answer for s1[0...i-1] and s2[0...j-1]
    // shifting indices by 1 to handle base cases easily (i=0 or j=0 means empty string)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = i; // deleting from s1 to match empty s2
    for (int j = 0; j <= m; j++) dp[0][j] = j; // inserting into empty s1 to match s2

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i][j - 1],   // Insert
                    dp[i - 1][j],   // Delete
                    dp[i - 1][j - 1] // Replace
                });
            }
        }
    }
    return dp[n][m];
}

// ============================================================================
// 4. SPACE OPTIMIZATION (Time: O(M*N), Space: O(M) - uses only 2 rows)
// ============================================================================
int editDistanceOpt(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    // We only ever need the previous row's data to calculate the current row
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    // Initialize base case for the dummy row 0
    for (int j = 0; j <= m; j++) prev[j] = j;

    for (int i = 1; i <= n; i++) {
        // Base case for the start of the current row (matching against empty s2)
        curr[0] = i; 
        
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = 1 + min({
                    curr[j - 1],   // Insert (left element in current row)
                    prev[j],       // Delete (top element from previous row)
                    prev[j - 1]    // Replace (diagonal element from previous row)
                });
            }
        }
        prev = curr;
    }
    return prev[m];
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    string s1 = "horse";
    string s2 = "ros";
    
    int m = s1.length();
    int n = s2.length();

    cout << "String 1: " << s1 << "\n";
    cout << "String 2: " << s2 << "\n\n";

    // 1. Pure Recursion
    // Start from the last indices (n-1, m-1)
    int ansRec = recursion(m - 1, n - 1, s1, s2);
    cout << "1. Pure Recursion Answer     : " << ansRec << endl;

    // 2. Memoization
    // 2D DP matrix initialized with -1
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ansMem = editDistanceMem(m - 1, n - 1, s1, s2, dp);
    cout << "2. Memoization Answer        : " << ansMem << endl;

    // 3. Tabulation
    int ansTab = editDistanceTab(s1, s2);
    cout << "3. Tabulation Answer         : " << ansTab << endl;

    // 4. Space Optimization
    int ansOpt = editDistanceOpt(s1, s2);
    cout << "4. Space Optimization Answer : " << ansOpt << endl;
    return 0;
}