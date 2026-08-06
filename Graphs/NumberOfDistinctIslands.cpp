#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void dfs(int row,int col,int baserow,int basecol,vector<vector<int>>&visited,vector<vector<int>>&grid,vector<pair<int,int>>&shape)
    {
        visited[row][col] = 1;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        shape.push_back({row-baserow,col-basecol});
        for(int i = 0;i<4;i++)
        {
            int nx = dx[i] + row;
            int ny = dy[i] + col;
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && !visited[nx][ny] && grid[nx][ny] == 1)
            {
                dfs(nx,ny,baserow,basecol,visited,grid,shape);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>&grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        set<vector<pair<int,int>>>st;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    int baserow = i;
                    int basecol = j;
                    vector<pair<int,int>>shape;
                    dfs(i,j,baserow,basecol,visited,grid,shape);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };
    Solution obj;
    cout << obj.countDistinctIslands(grid);
    return 0;
}