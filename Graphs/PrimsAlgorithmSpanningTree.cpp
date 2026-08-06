#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getSpanningTree(int V, vector<vector<int>> adj[]) {
        // Priority Queue stores: {weight, {current_node, parent_node}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<int> visited(V, 0);
        vector<pair<int, int>> mstEdges; // To store the edges of the MST
        int mstSum = 0;

        // Start with node 0. Parent is -1 because it's the root.
        pq.push({0, {0, -1}});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();

            if (visited[node]) continue;
            visited[node] = 1;
            mstSum += wt;
            if (parent != -1) {
                mstEdges.push_back({parent, node});
            }

            // Explore neighbors
            for (auto &it : adj[node]) {
                int neighbor = it[0];
                int edgeWeight = it[1];

                if (!visited[neighbor]) {
                    pq.push({edgeWeight, {neighbor, node}});
                }
            }
        }
        cout << "Total MST Sum: " << mstSum << endl;
        cout << "Edges in the MST:" << endl;
        for (auto &edge : mstEdges) {
            cout << edge.first << " -- " << edge.second << endl;
        }
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    Solution obj;
    obj.getSpanningTree(V, adj);
    return 0;
}