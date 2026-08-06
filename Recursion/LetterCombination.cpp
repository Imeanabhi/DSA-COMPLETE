#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void recursion(int i,int n,string digits,string& temp,vector<string>&ans,unordered_map<char,string>&map)
    {
        if(i == n)
        {
            ans.push_back(temp);
            return;
        }
        char digit = digits[i];
        for(auto it : map[digit])
        {
            temp.push_back(it);
            recursion(i+1,n,digits,temp,ans,map);
            temp.pop_back();
        }
    }

public:
    // Function to get all letter combinations for a given digit string
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>map = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        vector<string>ans;
        int n = digits.size();
        string temp = "";
        recursion(0,n,digits,temp,ans,map);
        return ans;
    }
};

int main() {
    Solution solution;
    string digits = "23"; // Input digits
    vector<string> result = solution.letterCombinations(digits); // Get combinations

    // Print the results
    for (const string& combination : result) {
        cout << combination << " ";
    }
    return 0;
}
