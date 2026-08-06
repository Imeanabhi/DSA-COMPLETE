#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    if (!(cin >> n >> m)) return 0; 

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        if (u <= n && u >= 0) {
            adj[u].push_back(v);
            
        }
    }

    return 0;
}