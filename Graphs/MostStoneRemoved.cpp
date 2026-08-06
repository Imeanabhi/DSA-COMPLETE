#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUlPar(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findUlPar(parent[u]); 
    }

    void UnionBySize(int u, int v) {
        int ulp_u = findUlPar(u);
        int ulp_v = findUlPar(v);
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        for (auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1; 
            ds.UnionBySize(rowNode, colNode);
        }

        /* Use Set or Just Find Normally
        unordered_set<int> uniqueComponents;
        for (auto& stone : stones) {
            uniqueComponents.insert(ds.findUlPar(stone[0]));
        }
        return stones.size() - uniqueComponents.size();
        */
        int ConnectedComponents = 0;
        vector<bool> visitedRoot(maxRow + maxCol + 2, false);

        for (auto& stone : stones) {
            int root = ds.findUlPar(stone[0]);
            // If we haven't seen this ultimate component root yet, count it!
            if (!visitedRoot[root]) {
                ConnectedComponents++;
                visitedRoot[root] = true;
            }
        }
        return stones.size() - ConnectedComponents;
    }
};

int main() {
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };

    Solution obj;
    cout << "Max stones removed: " << obj.removeStones(stones) << endl; // Output: 5
    return 0;
}