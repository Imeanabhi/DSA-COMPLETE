#include <bits/stdc++.h>
using namespace std;
class DisJointSet{
    public:
    vector<int>size,parent,rank;
    DisJointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if(parent[node] == node)return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_v]<size[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution{
private:
    // DelRow and delCol for neighbors
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    bool isValid(int &i, int &j, int &n) {
        
        // Return false if pixel is invalid
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= n) return false;
        
        // Return true if pixel is valid
        return true;
    }
    void addInitialIslands(vector<vector<int>>&grid,int n,DisJointSet &ds)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 0)continue;
                for(int k = 0;k < 4;k++)
                {
                    int row = i + delRow[k];
                    int col = j + delCol[k];
                    if(isValid(row,col,n)){
                        if(grid[row][col] == 1)
                        {
                            int Nodeno = i*n + j;
                            int Newno = row*n + col;
                            ds.unionBySize(Nodeno,Newno);

                        }
                    }
                }
            }
        }
    }
public:

    // Function to get the size of the largest island
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet ds(n*n);
        addInitialIslands(grid,n,ds);
        int ans = 0;

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1)continue;
                //  set to store the FindUPar parents of nodes
                set<int>st;
                for (int ind = 0; ind < 4; ind++) {
                    int newRow = i + delRow[ind];
                    int newCol = j + delCol[ind];
                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int nodeNo = newRow*n + newCol;
                        st.insert(ds.findUPar(nodeNo));
                    }
                }
                int sizeTotal = 0;
                for(auto it : st)
                {
                    sizeTotal += ds.size[it];
                }
                ans = max(ans,sizeTotal + 1);
            }
        }

        for(int i = 0;i<n*n;i++){
        ans = max(ans,ds.size[ds.findUPar(i)]);
        }
    return ans;
    }
};
int main() {
    vector<vector<int>> grid = {
        {1,0},
        {0,1}
    };
    Solution sol;
    int ans = sol.largestIsland(grid);
        cout << "The size of the largest island is: " << ans;
    
    return 0;
}