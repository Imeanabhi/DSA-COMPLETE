#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void recursion(int index,int dots,int n,string s, string temp,vector<string>&result)
    {
        if(dots == 4)
        {
            if(index == n)
            {
                temp.pop_back();
                result.push_back(temp);
            }
            return;
        }
        for(int i = 1;i<=3;i++)
        {
            if(index + i > n) break;
            string segment = s.substr(index,i);
            if(i > 1 && segment[0] == '0') break;
            int val = stoi(segment);
            if(val > 255) break;
            recursion(index+i,dots+1,n,s,temp + segment + '.',result);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.size();
        if(n<4 || n>12) return result;
        recursion(0,0,n,s,"",result);
        return result;
    }
};

// ================= DRIVER CODE =================
int main() {
    Solution sol;

    // Test cases
    vector<string> testCases = {
        "25525511135",
        "0000",
        "101023",
        "19216811"
    };

    for (const string& s : testCases) {
        cout << "Input string: \"" << s << "\"\n";
        vector<string> ipAddresses = sol.restoreIpAddresses(s);
        
        cout << "Valid IP Addresses:\n";
        if (ipAddresses.empty()) {
            cout << "  [None found]\n";
        } else {
            for (const string& ip : ipAddresses) {
                cout << "  - " << ip << "\n";
            }
        }
        cout << "------------------------------------\n";
    }
\
    return 0;
}