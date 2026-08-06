#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solveMemo(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& memo) {
    if (idx == nums.size()) return 0;
    if (memo[idx][prev_idx + 1] != -1) return memo[idx][prev_idx + 1];

    int skip = solveMemo(idx + 1, prev_idx, nums, memo);
    int nonskip = 0;
    if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
        nonskip = 1 + solveMemo(idx + 1, idx, nums, memo);
    }

    return memo[idx][prev_idx + 1] = max(skip, nonskip);
}

void printLIS_Memo(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return;

    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    int max_len = solveMemo(0, -1, nums, memo);

    // Backtrack using the memo table to print the sequence
    cout << "LIS (Memo Method): ";
    int prev_idx = -1;
    for (int idx = 0; idx < n; idx++) {
        int skip = (idx + 1 < n) ? memo[idx + 1][prev_idx + 1] : 0;
        int nonskip = 0;
        
        if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            nonskip = 1 + ((idx + 1 < n) ? memo[idx + 1][idx + 1] : 0);
        }

        // If nonskip choice was strictly better or forced, we include this element
        if (nonskip >= skip && (prev_idx == -1 || nums[idx] > nums[prev_idx])) {
            cout << nums[idx] << " ";
            prev_idx = idx; // Update the previous index context
        }
    }
    cout << "\nLength: " << max_len << "\n\n";
}