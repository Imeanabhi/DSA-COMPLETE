#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        long long limit = 1e9 + 7;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,1e18);
        vector<long long>ways(n,0);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d>dist[node]) continue;
            for(auto it : adj[node])
            {
                int wt = it.second;
                int neighbour = it.first;
                if(wt + d < dist[neighbour])
                {
                    dist[neighbour] = wt + d;
                    pq.push({wt+d,neighbour});
                    ways[neighbour] = ways[node];
                }
                else if(dist[neighbour] == wt + d)
                {
                    ways[neighbour] = (ways[node] + ways[neighbour])%limit;
                }
            }
        }
        return ways[n-1] % limit;
    }
};

int main() {
    int n = 7;
vector<vector<int>> roads = {
    {0,6,7}, {0,1,2}, {1,2,3}, {1,3,3}, {6,3,3}, 
    {3,5,1}, {6,5,1}, {2,5,1}, {0,4,5}, {4,6,2}
};    
    Solution obj;
    int ans = obj.countPaths(n,roads);
    cout << ans << endl;

    return 0;
}