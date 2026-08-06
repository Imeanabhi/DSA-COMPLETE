#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
                vector<vector<pair<int, int>>> adj(n + 1);
            for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        vector<int>dist(n+1,1e9);
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto it : adj[node])
            {
                int wt = it.second;
                int neighbour = it.first;
                if(dist[node] + wt < dist[neighbour])
                {
                    dist[neighbour] = wt + dist[node];
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        int minTime = *max_element(dist.begin()+1,dist.end());
        return minTime;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout << sol.networkDelayTime(times, n, k) << endl;
}
