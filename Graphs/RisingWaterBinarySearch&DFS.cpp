#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool dfs(int row,int col,vector<vector<int>>&grid,int Time,vector<vector<int>>&visited,int n)
    {
        if(row == n-1 && col == n-1) return true;
        visited[row][col] = 1;
        for(int i = 0;i<4;i++)
        {
            int nx = row + dx[i];
            int ny = col + dy[i];
            if(nx >=0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && grid[nx][ny] <= Time)
            {
                if(dfs(nx,ny,grid,Time,visited,n)){
                    return true;
                }
            }
        }
        return false;
    }
    bool canReach(vector<vector<int>>&grid,int Time,int n)
    {
        if(Time<grid[0][0])return false;
        vector<vector<int>>visited(n,vector<int>(n,0));
        return dfs(0,0,grid,Time,visited,n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = max(grid[0][0],grid[n-1][n-1]);
        int high = n*n-1;
        int ans = INT_MAX;
        while(low<=high)
        {
            int mid  = (low + high)/2;
            if(canReach(grid,mid,n))
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
int main() {
    Solution solver;
    vector<vector<int>> grid = {
        {0, 1, 3},
        {2, 4, 8},
        {9, 7, 5}
    };
    cout << "--- Testing Swim in Rising Water ---" << endl;
    cout << "Grid layout:" << endl;
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
    cout << "------------------------------------" << endl;
    int result = solver.swimInWater(grid);
    cout << "Minimum time required to swim to the bottom-right: " << result << endl;
    return 0;
}