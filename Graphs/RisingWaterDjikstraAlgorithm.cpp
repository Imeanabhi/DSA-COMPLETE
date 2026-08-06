#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n = grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        visited[0][0] = 1;
        while(!pq.empty())
        {
            int Time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == n-1) return Time;
            for(int i = 0;i<4;i++)
            {
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx >=0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    pq.push({max(Time,grid[nx][ny]),{nx,ny}});
                }
            }
        }
        return -1;
    }
};
int main() {
    vector<vector<int>> grid = {
        {0, 1, 3},
        {2, 4, 8},
        {9, 7, 5}
    };
    Solution sol;
    cout << "Minimum time to reach destination: " << sol.swimInWater(grid) << endl;
    return 0;
}
