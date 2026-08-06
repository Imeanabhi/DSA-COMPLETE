#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node,int col,vector<vector<int>>&adj,vector<int>&color)
    {
        color[node] = col;
        for(auto it : adj[node])
        {
            if(color[it] == -1)
            {
                if(dfs(it,!col,adj,color)==false) return false;
            }
        else if(col == color[it])return false;
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<vector<int>>& adj) {
        vector<int>color(V,-1);
        for(int i = 0;i<V;i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i,0,adj,color) == false) return false;
            }
        }
        return true;
    }
};

// 6. Pass by reference (&) so the changes persist in main
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    Solution obj;
    bool ans = obj.isBipartite(V, adj);
    if(ans) cout << "1\n";
    else cout << "0\n";
    return 0;
}