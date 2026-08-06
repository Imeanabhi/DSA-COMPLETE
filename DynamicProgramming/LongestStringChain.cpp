#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStringChain(vector<string>& words) {
        int n = words.size(); 
        sort(words.begin(), words.end(), compare);
        vector<int>dp(n,1);
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(checkPossible(words[i],words[j]) && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
    
private:
    bool static compare(string &s, string &t) {
        return s.size() < t.size();
    }
    bool checkPossible(string &s, string &t) {
    if(s.size() != t.size()+1) return false;
    int i = 0;
    int j = 0;
    while(i<s.size() && j<t.size())
    {
        if(s[i] == t[i])
        {
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return j == t.size();
    }
};


int main() {
    vector<string> words = {"a", "ab", "abc", "abcd", "abcde"};
    Solution sol;
    int lengthOfLongestStringChain = sol.longestStringChain(words);
    
    cout << "The length of the Longest String Chain is: " << lengthOfLongestStringChain << endl;
    
    return 0;
}