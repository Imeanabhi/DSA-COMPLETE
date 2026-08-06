#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool recursion(int index,long long prev1,long long prev2,int cnt,int n,string& num)
    {
        if(index == n)
        {
            return cnt >= 3;
        }
        for(int i = 1; i + index <= n;i++)
        {
            if(i>1 && num[index] == '0') break;
            if(i>17) break;
            long long current = stoll(num.substr(index,i));
            if(cnt >= 2)
            {
                long long expectedSum = prev1 + prev2;
                if(expectedSum < current) break;
                if(expectedSum > current) continue;
            }
        if(recursion(i+index,prev2,current,cnt+1,n,num));
        }
    }
bool isAdditiveNumber(string num) {
        int n = num.size();
        if (n < 3) return false;
        return recursion(0, 0, 0, 0, n, num);
    }
};
// ================= DRIVER CODE =================
int main() {
    Solution sol;
    vector<string> testCases = {
        "112358",    // 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8 -> true
        "199100199", // 1 + 99 = 100, 99 + 100 = 199 -> true
        "1023",      // Invalid -> false
        "101"        // 1 + 0 = 1 -> true
    };
    for (const string& num : testCases) {
        cout << "Input: \"" << num << "\" -> " 
             << (sol.isAdditiveNumber(num) ? "true" : "false") << "\n";
    }
    return 0;
}