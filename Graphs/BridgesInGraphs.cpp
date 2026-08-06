#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;
    void dfs(int node,int parent,vector<int>&visited,vector<vector<int>>&adj,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges)
    {
       visited[node] = 1;
       tin[node] = low[node] = timer++;
       for(auto it : adj[node])
       {
        if(it == parent) continue;
        if(!visited[it])
        {
            dfs(it,node,visited,adj,tin,low,bridges);
            low[node] = min(low[node],low[it]);
            // If the lowest reachable time from 'it' is strictly greater 
            // than discovery time of 'node', then (node, it) is a bridge
            if(low[it] > tin[node])
            {
                bridges.push_back({node,it});
            }
        }
        else{
            low[node] = min(low[node],tin[it]);
        }
    }
}

public:
    vector<vector<int>> criticalConnections(int n,
        vector<vector<int>>& connections) {

        // Step 1: Build adjacency list
        vector<vector<int>>adj(n);
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Initialize helper arrays
        vector<int> vis(n, 0);
        vector<int>tin(n); // Discovery time
        vector<int>low(n); // Lowest reachable time
        vector<vector<int>> bridges;

        // Step 3: Run DFS (assuming graph is connected)
        dfs(0,-1,vis,adj,tin,low,bridges);
        return bridges;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);

    cout << "Critical Connections (Bridges): ";
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}