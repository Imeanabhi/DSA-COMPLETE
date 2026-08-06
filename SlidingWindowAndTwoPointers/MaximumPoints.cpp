#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        
        // Step 1: Calculate the total sum of all cards
        for (int point : cardPoints) {
            totalSum += point;
        }
        
        // Edge case: If we take all cards
        if (k == n) return totalSum;
        
        // Size of the window we leave behind
        int windowSize = n - k;
        int currentWindowSum = 0;
        
        // Step 3: Get the sum of the first invalid window (0 to windowSize - 1)
        for (int i = 0; i < windowSize; i++) {
            currentWindowSum += cardPoints[i];
        }
        
        int minWindowSum = currentWindowSum;
        
        // Step 4: Slide the window across the array
        for (int i = windowSize; i < n; i++) {
            // Add the incoming element, remove the outgoing element
            currentWindowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, currentWindowSum);
        }
        
        // Step 5: Maximum score is Total - Minimum Leftover
        return totalSum - minWindowSum;
    }
};

// --- DRIVER CODE ---
int main() {
    Solution solver;

    // Test Case 1
    vector<int> cards1 = {1, 2, 3, 4, 5, 6, 1};
    int k1 = 3;
    // Explanation: Optimal choice is to pick 1 from beginning, then 6 and 1 from the end. Total = 1 + 6 + 1 = 8.
    cout << "Test Case 1 Max Score: " << solver.maxScore(cards1, k1) << " (Expected: 8)" << endl;

    // Test Case 2
    vector<int> cards2 = {2, 2, 2};
    int k2 = 2;
    // Explanation: Regardless of which cards you take, the score will be 4.
    cout << "Test Case 2 Max Score: " << solver.maxScore(cards2, k2) << " (Expected: 4)" << endl;

    // Test Case 3
    vector<int> cards3 = {9, 7, 7, 9, 7, 7, 9};
    int k3 = 7;
    // Explanation: k == n, so we take all cards. Total sum = 55.
    cout << "Test Case 3 Max Score: " << solver.maxScore(cards3, k3) << " (Expected: 55)" << endl;

    return 0;
}