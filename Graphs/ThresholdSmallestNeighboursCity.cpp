#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        for(int i = 0;i<n;i++) matrix[i][i] = 0;
        for(int k = 0;k < n; k++)
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j= 0 ; j < n ; j++)
                {
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int city = -1;
        int cntcity = n;
        for(int i = 0;i<n;i++)
        {
            int cnt  = 0;
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if(cnt<=cntcity)
            {
                cntcity = cnt;
                city = i;
            }
        }
        return city;
    }
};

int main() {
    int n = 4;
    int m = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;
    Solution obj;
    int cityNo = obj.findCity(n, m, edges, distanceThreshold);
    cout << "The answer is node: " << cityNo << endl;
    return 0;
}