#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && (grid[i][j] == 1))
                {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                    int drow = row + dx[i];
                    int dcol = col + dy[i];
                    if(drow>=0 && dcol>=0 && drow<m && dcol<n && !visited[drow][dcol] && grid[drow][dcol] == 1)
                    {
                        visited[drow][dcol] = 1;
                        q.push({drow,dcol});
                    }
                }
            }
        int cnt = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
    };

int main() {
    // Define the grid
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;
    return 0;
}
