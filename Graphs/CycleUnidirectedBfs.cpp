#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool detectCycle(int V,vector<int>&visited,vector<int>adj[],int src)
    {
        visited[src] = 1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty())
        {
            int son = q.front().first;
            int father = q.front().second;
            q.pop();
            for(auto it : adj[son])
            {
                if(!visited[it])
                {
                    visited[it] = 1;
                    q.push({it,son});
                }
                else if (father != it)
                {
                    return true;
                }
            }
        }
    }
    bool isCycle(int V,vector<int>adj[])
    {
        vector<int>visited(V,0);
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycle(V,visited,adj,i)) return true;
            }
        }
        return false;
    }
};

int main() {
    
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}