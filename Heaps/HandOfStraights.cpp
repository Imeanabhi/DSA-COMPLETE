#include <vector>
#include <map>
#include <iostream> // Added for printing results
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        map<int, int> mp;
        for (auto it : hand) {
            mp[it]++;
        }
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int node = it->first;
            int count = mp[node]; 
            
            if (count > 0) {
                for (int i = 0; i < groupSize; i++) {
                    int nextcard = node + i;
                    
                    if (mp[nextcard] < count) {
                        return false;
                    }
                    mp[nextcard] -= count;
                }
            }
        }
        return true;
    }
};

// ============================================================================
// ADD THIS MAIN FUNCTION AT THE BOTTOM OF YOUR FILE
// ============================================================================
int main() {
    Solution solver;
    
    // Test Case 1: Expected output: 1 (true)
    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;
    cout << "Test 1: " << solver.isNStraightHand(hand1, groupSize1) << endl;

    // Test Case 2: Expected output: 0 (false)
    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 4;
    cout << "Test 2: " << solver.isNStraightHand(hand2, groupSize2) << endl;

    return 0;
}