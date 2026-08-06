class DSU {
public:
    vector<int> parent;
    int components;
    
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
private:
    // Helper function to build an MST with options to force include or exclude an edge
    int buildMST(int n, vector<vector<int>>& edges, int skip_idx, int force_idx) {
        DSU dsu(n);
        int weight = 0;
        
        // If an edge is forced, add it to the DSU structure first
        if (force_idx != -1) {
            for (const auto& edge : edges) {
                if (edge[3] == force_idx) {
                    dsu.unite(edge[0], edge[1]);
                    weight += edge[2];
                    break;
                }
            }
        }
        
        // Process remaining edges in sorted order
        for (const auto& edge : edges) {
            if (edge[3] == skip_idx) continue;
            
            if (dsu.unite(edge[0], edge[1])) {
                weight += edge[2];
            }
        }
        
        // If the graph is not fully connected, return infinity
        if (dsu.components > 1) return 1e9;
        return weight;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Step 1: Store original indices [u, v, weight, original_index]
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        
        // Step 2: Sort edges by weight for Kruskal's Algorithm
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        // Step 3: Find baseline MST weight
        int base_weight = buildMST(n, edges, -1, -1);
        
        vector<int> critical;
        vector<int> pseudo_critical;
        
        // Step 4: Test each individual edge
        for (int i = 0; i < edges.size(); i++) {
            int original_idx = edges[i][3];
            
            // Exclusion test
            if (buildMST(n, edges, original_idx, -1) > base_weight) {
                critical.push_back(original_idx);
            } 
            // Inclusion test
            else if (buildMST(n, edges, -1, original_idx) == base_weight) {
                pseudo_critical.push_back(original_idx);
            }
        }
        
        return {critical, pseudo_critical};
    }
};