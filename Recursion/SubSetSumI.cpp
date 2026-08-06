#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to generate subset sums recursively
    void findSums(int index, int currentSum, vector<int>& arr, vector<int>& sums) {
        // Base case: if we have considered all elements
        if (index == arr.size()) {
            sums.push_back(currentSum);
            return;
        }

        // Include current element
        findSums(index + 1, currentSum + arr[index], arr, sums);

        // Exclude current element
        findSums(index + 1, currentSum, arr, sums);
    }

    // Main function
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums;
        findSums(0, 0, arr, sums);
        sort(sums.begin(), sums.end()); // Sort in increasing order
        return sums;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr = {5, 2, 1};
    vector<int> result = sol.subsetSums(arr);

    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
