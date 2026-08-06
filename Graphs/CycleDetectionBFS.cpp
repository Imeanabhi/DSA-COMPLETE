#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
  bool detect(int src, vector<vector<int>>&adj, vector<int>&vis) {
    vis[src] = 1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                q.push({it,node});
                vis[it] = 1;
            }
            else if(it!=parent)
            {
                return true;
            }
        }
    }
    return false;
}

  public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        // initialise them as unvisited 
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true;
            }
        }
        return false; 
    }
};
int main() {
    
    // V = 4, E = 2
    vector<vector<int>> adj = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}