#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int CountForLength(int k)
    {
        if(k == 1) return 9; 
        int choices = 10 - (k-1);
        return choices*CountForLength(k-1);
    }
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        return CountForLength(n) + countNumbersWithUniqueDigits(n-1);
    }
};

// ================= DRIVER CODE =================
int main() {
    Solution sol;

    vector<int> testCases = {0, 1, 2, 3,4,5,6,7,8,9,10,11};

    for (int n : testCases) {
        cout << "n = " << n << " -> Total Unique Digit Numbers: " 
            << sol.countNumbersWithUniqueDigits(n) << "\n";
    }

    return 0;
}