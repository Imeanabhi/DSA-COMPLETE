#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the longest common prefix in a list of strings
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        string s1 = str[0];
        string s2 = str[str.size()-1];
        int len = min(s1.length(),s2.length());
        string ans = "";
        for(int i = 0;i<len;i++)
        {
            if(s1[i]!=s2[i])break;
            ans += s1[i];
        }
        return ans;
    }
};

int main() {
    // Create instance of Solution
    Solution solution;

    // Input list of strings
    vector<string> input = {"interview", "internet", "internal", "interval"};

    // Get the result
    string result = solution.longestCommonPrefix(input);

    // Print the result
    cout << "Longest Common Prefix: " << result << endl; 

    return 0;
}
