#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void topoSort(int node,vector<vector<pair<int,int>>>&adj,stack<int>&st,vector<int>&visited)
    {
        visited[node] = 1;
        for(auto it : adj[node])
        {
            int element = it.first;
            if(!visited[element])
            {
                topoSort(element,adj,st,visited);
            }
        }
        st.push(node);
    }
    public:
    vector<int>shortestPath(int V,int E,vector<vector<int>>&edges)
    {
        vector<vector<pair<int,int>>>adj(V);
        for(auto it : edges)
        {
            int node = it[0];
            int neighbour = it[1];
            int wt = it[2];
            adj[node].push_back({neighbour,wt});
        }
        vector<int>visited(V,0);
        stack<int>st;
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                topoSort(i,adj,st,visited);
            }
        }
        vector<int>dist(V,1e9);
        dist[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(auto it : adj[node])
            {
                int element = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[element])
                {
                    dist[element] = dist[node] + wt;
                }
            }
        }
        vector<int>ans(V,-1);
        for(int i = 0;i<V;i++)
        {
            if(dist[i]!=1e9)
            {
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};

// Driver code
int main() {

  // Number of nodes and edges
  int N = 6, M = 7;

  // Edge list input
  vector<vector<int>> edges = {
    {0, 1, 2},
    {0, 4, 1},
    {4, 5, 4},
    {4, 2, 2},
    {1, 2, 3},
    {2, 3, 6},
    {5, 3, 1}
  };

  // Create object of Solution class
  Solution obj;

  // Call shortestPath function
  vector<int> ans = obj.shortestPath(N, M, edges);

  // Print the resulting shortest distances
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
