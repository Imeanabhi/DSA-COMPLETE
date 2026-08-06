#include <iostream>
#include <vector>
#include <cmath>     // For std::abs
#include <algorithm> // For std::min
#include <climits>   // For INT_MAX

using namespace std;

class FrogJump {
private:
    // Helper function to calculate minimum energy recursively
    int solve(int ind, const vector<int>& heights) {

        if(ind == 0) return 0;
        int jumpone = solve(ind-1,heights) + abs(heights[ind]-heights[ind-1]);
        int jumpTwo = INT_MAX;
        if(ind>1)
        {
            jumpTwo = solve(ind-2,heights) + abs(heights[ind] - heights[ind-2]);
        }
        return min(jumpone,jumpTwo);
    }

public:
    int minEnergy(int n, const vector<int>& heights) {
        // We want to reach the last index (n - 1)
        return solve(n - 1, heights);
    }

        int solveMemo(int ind,const vector<int>&heights,vector<int>&memo)
        {
            if(ind == 0) return 0;
            if(memo[ind] != -1) return memo[ind];
            int jumpone = solveMemo(ind-1,heights,memo) + abs(heights[ind]-heights[ind-1]);
            int jumpTwo = INT_MAX;
            if(ind>1)
            {
            jumpTwo = solveMemo(ind-2,heights,memo) + abs(heights[ind] - heights[ind-2]);
            }
        return memo[ind] = min(jumpone,jumpTwo);
        }
    int minEnergyMemo(int n, const vector<int>& heights) {
        // We want to reach the last index (n - 1)
        vector<int>memo(n,-1);
        return solveMemo(n - 1, heights,memo);
    }

    #include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class FrogJump {
public:
    int minEnergyTable(int n, const vector<int>& heights) {
        if (n <= 1) return 0;

        // dp[i] will store the minimum energy to reach stair i
        vector<int> dp(n, 0);
        
        // Base case
        dp[0] = 0; 

        for (int i = 1; i < n; ++i) {
            int jumpOne = dp[i - 1] + abs(heights[i] - heights[i - 1]);
                        int jumpTwo = INT_MAX;
            if (i > 1) {
                jumpTwo = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            }
            dp[i] = min(jumpOne, jumpTwo);
        }

        return dp[n - 1];
    }
};
};

int main() {
    FrogJump solver;
    vector<int> heights = {10, 30, 40, 20};
    int n = heights.size();
    cout << "Minimum energy required: " << solver.minEnergy(n, heights) << " units\n";
    cout << "Minimum energy required: " << solver.minEnergyMemo(n, heights) << " units\n";
        cout << "Minimum energy required: " << solver.minEnergyTable(n, heights) << " units\n";

    return 0;
}