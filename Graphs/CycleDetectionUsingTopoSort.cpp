#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(int V,vector<vector<int>>&adj)
    {
        vector<int>visited(V,0);
        vector<int>indegree(V,0);
        for(int i = 0;i<V;i++)
        {
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i =0;i<V;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return count!=V;
    }
};


int main() {
    int V = 4;
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}
    };

    Solution obj;
    if (obj.hasCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";
    return 0;
}