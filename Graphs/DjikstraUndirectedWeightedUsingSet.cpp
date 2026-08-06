#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int>dijkstra(int V,vector<vector<int>>adj[],int src)
    {
        vector<int>dist(V,1e9);
        set<pair<int,int>>st;
        dist[src] = 0;
        st.insert({0,src});
        while(!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int wt = it.first;
            st.erase(it);
            for(auto it : adj[node])
            {
                int element = it[0];
                int d = it[1];
                if(dist[node] + d < dist[element])
                {
                    if(dist[element] != 1e9){
                            st.erase({dist[element], element});
                    }
                    dist[element] = d + dist[node];
                    st.insert({dist[element],element});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int V = 3, E = 3, S = 2;  // Number of vertices, edges, and source vertex
    // we either use a 3 dimensional Vector or a vector<vector<pair<int,int>>>
    vector<vector<int>> adj[V]; // Adjacency list representation of the graph
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);
    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
