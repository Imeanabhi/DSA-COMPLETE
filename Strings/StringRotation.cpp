#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if goal is a rotation of s using string doubling method
    bool rotateString(string& s, string& goal) {
    if(s.length()!=goal.length()) return false;
    string temp = s + s;
    return temp.find(goal)!=string::npos;
    }
};

int main() {
    Solution sol;

    string s = "rotation";
    string goal = "tionrota";
    cout << (sol.rotateString(s, goal) ? "true" : "false") << endl;

    return 0;
}