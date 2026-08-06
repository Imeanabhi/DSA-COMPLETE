#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper to print vectors neatly
void printVector(const vector<int>& vec) {
    cout << "{ ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << " }" << endl;
}

// ==========================================
// 1. RECURSIVE APPROACH (Returning Vectors)
// ==========================================
vector<int> solveRec(int idx, int prev_idx, vector<int>& nums) {
    if (idx == nums.size()) return {};

    // Option 1: Skip the current element
    vector<int> skip = solveRec(idx + 1, prev_idx, nums);

    // Option 2: Take the current element (if valid)
    vector<int> take = {};
    if (prev_idx == -1 || nums[idx] % nums[prev_idx] == 0) {
        take = solveRec(idx + 1, idx, nums);
        take.insert(take.begin(), nums[idx]); // Prepend current element
    }

    // Return the longer subset
    return (take.size() > skip.size()) ? take : skip;
}

vector<int> getLDSRecursive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return solveRec(0, -1, nums);
}


// ==========================================
// 2. MEMOIZATION APPROACH
// ==========================================
// We cache the *lengths* in a table, then use that same table 
// to reconstruct the path after the DP completes.
int solveMemo(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& memo) {
    if (idx == nums.size()) return 0;
    if (memo[idx][prev_idx + 1] != -1) return memo[idx][prev_idx + 1];

    int skip = solveMemo(idx + 1, prev_idx, nums, memo);
    int take = 0;
    if (prev_idx == -1 || nums[idx] % nums[prev_idx] == 0) {
        take = 1 + solveMemo(idx + 1, idx, nums, memo);
    }

    return memo[idx][prev_idx + 1] = max(skip, take);
}

// Reconstructs the vector using the filled memo table
void traceMemoPath(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& memo, vector<int>& lds) {
    if (idx == nums.size()) return;

    int skipLen = solveMemo(idx + 1, prev_idx, nums, memo);
    int takeLen = 0;
    if (prev_idx == -1 || nums[idx] % nums[prev_idx] == 0) {
        takeLen = 1 + solveMemo(idx + 1, idx, nums, memo);
    }

    // Follow the choice that yielded the maximum length
    if (takeLen > skipLen) {
        lds.push_back(nums[idx]);
        traceMemoPath(idx + 1, idx, nums, memo, lds);
    } else {
        traceMemoPath(idx + 1, prev_idx, nums, memo, lds);
    }
}

vector<int> getLDSMemo(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n == 0) return {};
    
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    // Step 1: Run the memoized function to populate the cache table
    solveMemo(0, -1, nums, memo);
    
    // Step 2: Reconstruct the path based on the table choices
    vector<int> lds;
    traceMemoPath(0, -1, nums, memo, lds);
    return lds;
}


// ==========================================
// 3. BOTTOM-UP ITERATIVE DP
// ==========================================
vector<int> getLDSDp(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> parent(n, -1); // Keeps track of the chain sequence

    int max_len = 1;
    int last_index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            last_index = i;
        }
    }

    // Backtrack from last_index to build the result
    vector<int> lds;
    while (last_index != -1) {
        lds.push_back(nums[last_index]);
        last_index = parent[last_index];
    }
    reverse(lds.begin(), lds.end());
    return lds;
}


// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    vector<int> nums1 = {4, 8, 10, 1, 2};
    vector<int> nums2 = {1, 2, 3, 6};
    vector<int> nums3 = {7, 7, 7, 7, 7};

    cout << "--- 1. Pure Recursive Results ---" << endl;
    cout << "nums1: "; printVector(getLDSRecursive(nums1));
    
    cout << "\n--- 2. Memoization Results ---" << endl;
    cout << "nums2: "; printVector(getLDSMemo(nums2));
    
    cout << "\n--- 3. Iterative DP Results ---" << endl;
    cout << "nums3: "; printVector(getLDSDp(nums3));

    return 0;
}