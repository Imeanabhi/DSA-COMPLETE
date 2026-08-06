#include <bits/stdc++.h>
using namespace std;

// Solution class to generate all subsequences using recursion
class Solution {
public:
    // Helper recursive function to generate subsequences
    void helper(string &s, int index, string t, vector<string> &result) {
        if(s.size() == index)
        {
            result.push_back(t);
            return;
        }
        helper(s,index+1,t,result);

        t.push_back(s[index]);
        helper(s,index+1,t,result);
        t.pop_back();
    }

    vector<string> getSubsequences(string s) {
        vector<string> result;  
        string current = "";    
        helper(s, 0, current, result);
        return result;
    }
};

int main() {
    // Input string
    string s = "abc";

    // Create Solution object
    Solution sol;

    // Get all subsequences
    vector<string> subsequences = sol.getSubsequences(s);

    // Print all subsequences
    for (auto &subseq : subsequences) {
        cout << "\"" << subseq << "\"" << endl;
    }

    return 0;
}
