#include <iostream>
#include <vector>
#include <algorithm>

class RodCutting {
private:
    // Helper function for Memoization (Top-Down DP)
    int memoizationHelper(int n, const std::vector<int>& price, std::vector<int>& memo) {
        if (n <= 0) return 0;
        
        if (memo[n] != -1) return memo[n];

        int max_val = 0;
        for (int i = 1; i <= n; ++i) {
            max_val = std::max(max_val, price[i - 1] + memoizationHelper(n - i, price, memo));
        }

        return memo[n] = max_val;
    }

public:
    int cutRodRecursive(int n, const std::vector<int>& price) {
        if (n <= 0) return 0;
        int max_val = 0;
        for (int i = 1; i <= n; ++i) {
            max_val = std::max(max_val, price[i - 1] + cutRodRecursive(n - i, price));
        }
        return max_val;
    }
    int cutRodMemoization(int n, const std::vector<int>& price) {
        std::vector<int> memo(n + 1, -1);
        return memoizationHelper(n, price, memo);
    }

    int cutRodTabulation(int n, const std::vector<int>& price) {
        std::vector<int> dp(n + 1, 0);

        for (int j = 1; j <= n; ++j) {
            int max_val = 0;
            for (int i = 1; i <= j; ++i) {
                max_val = std::max(max_val, price[i - 1] + dp[j - i]);
            }
            dp[j] = max_val;
        }

        return dp[n];
    }
};

int main() {
    // Index 0 represents length 1, Index 1 represents length 2, and so on.
    std::vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size(); // Length of the rod (8 in this case)

    RodCutting solver;

    std::cout << "--- Rod Cutting Problem Max Value Results ---" << std::endl;
    std::cout << "1. Recursion:  " << solver.cutRodRecursive(n, price) << std::endl;
    std::cout << "2. Memoization: " << solver.cutRodMemoization(n, price) << std::endl;
    std::cout << "3. Tabulation:  " << solver.cutRodTabulation(n, price) << std::endl;

    return 0;
}