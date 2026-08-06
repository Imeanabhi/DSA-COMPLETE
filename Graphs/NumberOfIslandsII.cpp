#include <bits/stdc++.h>
using namespace std;

class DisJointSet{
    public:
    vector<int>size,parent;
    DisJointSet(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        if(parent[node] == node)return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
// Solution to find the number of islands after each operation
class Solution {
private:
    bool isValid(int row, int col, int n, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        DisJointSet dsu(n*m);
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt = 0;
        vector<int>ans;
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if(visited[row][col])
            {
            ans.push_back(cnt);
            continue;
            }
            visited[row][col] = 1;
            cnt++;
            int dx[4] = {0,0,-1,1};
            int dy[4] = {1,-1,0,0};
            for(int i = 0;i<4;i++)
            {
                int adjrow = row + dx[i];
                int adjcol = col + dy[i];
                if(isValid(adjrow,adjcol,n,m))
                {
                    if(visited[adjrow][adjcol])
                    {
                        int nodeNo = row*m + col;
                        int adjNo = adjrow*m + adjcol;
                        if(dsu.findUPar(nodeNo) != dsu.findUPar(adjNo))
                        {
                            cnt--;
                            dsu.unionBySize(nodeNo,adjNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
