#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Using long long to handle large string lengths
    long long atMost(string s, int k) {
        if (k < 0) return 0; // Edge case: k-1 could be -1
        
        int l = 0, r = 0;
        long long count = 0;
        // Using a vector/array for speed (assuming ASCII/lowercase)
        or use a map
        vector<int> freq(256, 0); 
        int distinct = 0;

        while (r < s.length()) {
            if (freq[s[r]] == 0) distinct++;
            freq[s[r]]++;

            while (distinct > k) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) distinct--;
                l++;
            }
            
            // Current window size [l...r] adds (r - l + 1) new substrings
            count += (r - l + 1);
            r++;
        }
        return count;
    }

    long long countSubstrings(string s, int k) {
        return atMost(s, k) - atMost(s, k - 1);
    }
};

int main() {
    Solution sol;
    string s = "pqp";
    int k = 2;
    
    cout << "Number of substrings with exactly " << k << " distinct characters: " 
         << sol.countSubstrings(s, k) << endl;

    return 0;
}