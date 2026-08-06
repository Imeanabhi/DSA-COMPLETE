#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <stack> // Added missing header

using namespace std;
class Solution {
public:
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    int calculate(string s) {
        int n = s.size();
        int currNo = 0;
        stack<int>st;
        char lastop = '+';
        for(int i = 0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                currNo = currNo*10 + (s[i] - '0');
            }
            if(isOperator(s[i]) || i == n-1){
                if(lastop == '+')
                {
                    st.push(currNo);
                }
                else if(lastop == '-')
                {
                    st.push(-currNo);
                }
                else if(lastop == '*')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top*currNo);
                }
                else if(lastop == '/')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top / currNo);
                }
                lastop = s[i];
                currNo = 0;
            }
        }
            int total = 0;
            while(!st.empty())
            {
                total += st.top();
                st.pop();
            }
        return total;
    }
};
// ==================== DRIVER CODE ====================
int main() {
    Solution solver;

    std::vector<std::pair<std::string, int>> testCases = {
        {"3+2*2", 7},
        {" 3/2 ", 1},
        {" 3+5 / 2 ", 5},
        {"100000000/1/2/3", 16666666},
        {"14-3/2*2", 12},
        {"0-2147483647", -2147483647}
    };

    std::cout << "Running Basic Calculator II Tests:\n";
    std::cout << "------------------------------------\n";

    for (size_t i = 0; i < testCases.size(); ++i) {
        std::string expr = testCases[i].first;
        int expected = testCases[i].second;
        int actual = solver.calculate(expr);

        std::cout << "Test " << i + 1 << ": \"" << expr << "\"\n";
        std::cout << "   Output:   " << actual << "\n";
        std::cout << "   Expected: " << expected << "\n";
        std::cout << "   Status:   " << (actual == expected ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}