#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    double power(double x, long n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n %  2 == 0)
        {
            return power(x*x,n/2);
        }
        return x*power(x,n-1);
    }

public:
    // Function to calculate x raised to n
    double myPow(double x, int n) {
        int num = n;
        if(num<0)
        {
            return power(1.0/x,-1*n);
        }
        return power(x,n);
    }
};

int main() {
    Solution sol;
    double x = 2.0;
    int n = 10;

    // Calculate x raised to n
    double result = sol.myPow(x, n);

    // Print the result
    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}