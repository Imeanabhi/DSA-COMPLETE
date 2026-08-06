#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Helper function to check if a substring s[left...right] is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void backtrack(int index, const string& s, vector<string>& currentPath, vector<vector<string>>& result) {
        if(index == s.size())
        {
            result.push_back(currentPath);
            return;
        }


        for(int i = index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                currentPath.push_back(s.substr(index,i-index+1));
                backtrack(i+1,s,currentPath,result);
                currentPath.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPath;
        backtrack(0, s, currentPath, result);
        return result;
    }
};

int main() {
    Solution solver;
    string s = "aab";
    vector<vector<string>> partitions = solver.partition(s);

    // Display the results
    cout << "All valid palindrome partitions for \"" << s << "\":" << endl;
    for (const auto& partition : partitions) {
        cout << "[ ";
        for (const string& str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}