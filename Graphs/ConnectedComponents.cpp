#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countComponents(int V,vector<vector<int>>&edges)
    {
        int components = 0;
        vector<int>visited(V,0);
        vector<vector<int>>adj(V);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i =  0;i<V;i++)
        {
            if(visited[i] == 0)
            {
                components++;
                visited[i] = 1;
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node])
                    {
                        if(visited[it] == 0)
                        {
                            q.push(it);
                            visited[it] = 1;
                        }
                    }
                }
            }
        }
        return components;
    }
};


int main() {
    int V = 5;

    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};

    Solution sol;

    cout << "Number of Connected Components: " 
         << sol.countComponents(V, edges) << endl;

    return 0;
}