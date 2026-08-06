#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int>dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(wt > dist[node]) continue;
            for(auto neighbour: adj[node])
            {
                int it = neighbour.first;
                int d = neighbour.second;
                if(wt + d < dist[it])
                {
                    dist[it] = dist[node] + d;
                    pq.push({dist[it],it});
                }
            }
        }
        return dist;
        }
};

int main() {
    int V = 5;
    // Adjacency list {neighbor, weight}
    vector<vector<pair<int,int>>> adj(V);
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 2});
    Solution obj;
    vector<int> dist = obj.dijkstra(V, adj, 0);
    for (int i = 0; i < V; i++) {
        cout << "Distance from 0 to " << i << " = " << dist[i] << endl;
    }
}
