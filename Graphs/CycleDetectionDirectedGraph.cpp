#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], vector<int>&Visited,vector<int>&pathVisited) {
    Visited[node] = 1;
    pathVisited[node] = 1;
    for(auto it : adj[node])
    {
        if(!Visited[it])
        {
            if(dfsCheck(it,adj,Visited,pathVisited)) return true;
        }
        else if(pathVisited[it])
        {
            return true;
        }
    }
    pathVisited[node] = 0;
    return false;
	}
public:
	bool isCyclic(int V, vector<int> adj[]) {
        vector<int>Visited(V,0);
        vector<int>pathVisited(V,0);
		for (int i = 0; i < V; i++) {
			if (!Visited[i]) {
				if (dfsCheck(i, adj, Visited, pathVisited)) return true;
			}
		}
		return false;
	}
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}
