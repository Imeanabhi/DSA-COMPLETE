#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class CandySolution {
public:
    // Method 1: Two-Pass Array Approach
    // Time: O(N), Space: O(N)
    int candyTwoPass(const std::vector<int>& ratings) {
       int n = ratings.size();
       if(n<=1)return n;
       vector<int>candies(n,1);
       for(int i = 1;i<n;i++)
       {
        if(ratings[i] > ratings[i-1])
        {
            candies[i] = candies[i-1] + 1;
        }
       }
       for(int i = n-2;i>=0;i--)
       {
        if(ratings[i+1] < ratings[i])
        {
            candies[i] = max(candies[i],candies[i+1]+1);
        }
    }
    return accumulate(candies.begin(),candies.end(),0);
    }
    int candyOnePass(const std::vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1)return n;
        int up = 0;
        int down = 0;
        int peak = 0;
        int totalCandies = 1;
        int i = 1;
        while(i<n)
        {
            if(ratings[i] == ratings[i-1])
            {
                up = 0;
                down = 0;
                peak = 0;
                totalCandies += 1;
            }
            else if(ratings[i]>ratings[i-1])
            {
                up++;
                peak = up;
                down = 0;
                totalCandies += (1 + up);
            }
            else{
                down++;
                up = 0;
                totalCandies += down + (down>peak ? 1 : 0);
            }
            i++;
        }
        return totalCandies;
    }
};

int main() {
    CandySolution solver;
    
    // Test Case: A mix of peaks, valleys, and flat ratings
    std::vector<int> ratings = {1, 2, 2, 5, 4, 3, 2};
    
    std::cout << "--- Candy Greedy Problem Solver ---" << std::endl;
    std::cout << "Ratings Array: ";
    for (int r : ratings) std::cout << r << " ";
    std::cout << "\n\n";

    // Executing Method 1
    int result1 = solver.candyTwoPass(ratings);
    std::cout << "[Method 1] Two-Pass Array (O(N) Space): " << result1 << " candies." << std::endl;
    
    // Executing Method 2
    int result2 = solver.candyOnePass(ratings);
    std::cout << "[Method 2] Peak & Valley (O(1) Space): " << result2 << " candies." << std::endl;
    
    return 0;
}