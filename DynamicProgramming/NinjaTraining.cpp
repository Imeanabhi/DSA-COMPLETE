#include <bits/stdc++.h>
using namespace std;

// ==========================================
// 1. Pure Recursive Approach (Fixed Name)
// ==========================================
int recursion(int day, int last, vector<vector<int>> &points) {
    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i <= 2; i++) {
            if (i != last) {
                maxi = max(maxi, points[day][i]);
            }
        }
        return maxi;
    }
    
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != last) {
            int activity = points[day][i] + recursion(day - 1, i, points);
            maxi = max(maxi, activity);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    return recursion(n - 1, 3, points); // Fixed: calling matching function name
}

// ==========================================
// 2. Memoization Approach (Top-Down)
// ==========================================
int recursionmemo(int day, int last, vector<vector<int>> &points, vector<vector<int>> &memo) {
    if (memo[day][last] != -1) return memo[day][last];
    
    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i <= 2; i++) {
            if (i != last) {
                maxi = max(maxi, points[day][i]);
            }
        }
        return memo[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != last) {
            int activity = points[day][i] + recursionmemo(day - 1, i, points, memo);
            maxi = max(maxi, activity);
        }
    }
    return memo[day][last] = maxi;
}

int ninjaTrainingMemo(int n, vector<vector<int>> &points) {
    int m = points[0].size();
    // Size is n x 4 because 'last' can range from 0 to 3
    vector<vector<int>> memo(n, vector<int>(m + 1, -1));
    return recursionmemo(n - 1, 3, points, memo);
}

// ==========================================
// 3. Tabulation Approach (Bottom-Up DP)
// ==========================================
int ninjaTrainingTabulation(int n, vector<vector<int>> &points) {
    // dp[day][last_activity]
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case: Day 0
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    //dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    // Iteratively build the table for subsequent days
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    // The answer is the max merit points achievable on the final day, 
    // assuming no activity restrictions prior to the start (last = 3).
    return dp[n - 1][3];
}

// ==========================================
// Main Function
// ==========================================
int main() {
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();

    cout << "Recursive:  " << ninjaTraining(n, points) << endl;
    cout << "Memoization: " << ninjaTrainingMemo(n, points) << endl;
    cout << "Tabulation:  " << ninjaTrainingTabulation(n, points) << endl;

    return 0;
}