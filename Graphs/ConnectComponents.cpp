#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0;i<=n;i++)
        {
            parent[i] = i;
        }
    }

        int findUlPar(int u)
        {
            if(parent[u] == u) return u;
            return parent[u] = findUlPar(parent[u]);
        }

        void UnionBySize(int u,int v)
        {
            int ulp_u = findUlPar(u);
            int ulp_v = findUlPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            }
            else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            }
        }

        bool isParentItself(int node)
        {
            return parent[node] == node;
        }
    };
class Solution{
    public:
    int makeConnected(int n, vector<vector<int>>&connections)
    {
        if (connections.size() < n - 1) return -1;
        DisjointSet ds(n);
        int cntextras = 0;
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findUlPar(u) == ds.findUlPar(v))
            {
                cntextras++;
            }
            else{
            ds.UnionBySize(u,v);
            }
        }
        int cntconnected = 0;
        for(int i = 0;i<n;i++)
        {
            if(ds.isParentItself(i))
            {
                cntconnected++;
            }
        }
        int ans = cntconnected-1;
        if(cntextras>=ans)return ans;
        return -1;
    }
};


int main() {
    Solution solver;
    int n1 = 4;
    vector<vector<int>> connections1 = {{0, 1}, {0, 2}, {1, 2}};
    cout << "Test Case 1: n = 4, connections = [[0,1],[0,2],[1,2]]\n";
    cout << "Expected: 1, Got: " << solver.makeConnected(n1, connections1) << "\n\n";

    // Test Case 2: Not enough total cables overall
    int n2 = 6;
    vector<vector<int>> connections2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    cout << "Test Case 2: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]\n";
    cout << "Expected: -1, Got: " << solver.makeConnected(n2, connections2) << "\n\n";

    // Test Case 3: Already fully connected
    int n3 = 6;
    vector<vector<int>> connections3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {4, 5}};
    cout << "Test Case 3: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3],[4,5]]\n";
    cout << "Expected: 1, Got: " << solver.makeConnected(n3, connections3) << "\n";

    return 0;
}