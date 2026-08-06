#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MinimumEffort(vector<vector<int>> &heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        pq.push({0,{0,0}});

        int dx[4] = {0,0,1,-1};
        int dy[4] = {-1,1,0,0};
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == m-1 && col == n-1) return diff;
            for(int i = 0;i<4;i++)
            {
                int newr = dx[i] + row;
                int newc = dy[i] + col;
                if(newr>=0 && newc>=0 && newr<m && newc<n)
                {
                    int effort = max(abs(heights[newr][newc]-heights[row][col]),diff);
                    if(effort<dist[newr][newc])
                    {
                        dist[newr][newc] = effort;
                        pq.push({effort,{newr,newc}});
                    }
                }
            }

        }
        return 0;
    }
};

int main() {
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    Solution obj;
    int ans = obj.MinimumEffort(heights);
    cout << ans << endl;

    return 0;
}