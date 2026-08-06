#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights,int src, int dst, int K)
    {

        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        pq.push({0,{src,0}});
        while(!pq.empty())
        {
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int d = pq.top().second.second;
            pq.pop();
            if(stops>K) continue;
            for(auto it : adj[node])
            {
                int neighbour = it.first;
                int wt = it.second;
                if(d + wt < dist[neighbour])
                {
                    dist[neighbour] = dist[node] + wt;
                    pq.push({stops+1,{neighbour,wt + d}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main()
{

    int n = 4, src = 0, dst = 3, K = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};
    Solution obj;
    int ans = obj.CheapestFLight(n, flights, src, dst, K);
    cout << ans << endl;

    return 0;
}