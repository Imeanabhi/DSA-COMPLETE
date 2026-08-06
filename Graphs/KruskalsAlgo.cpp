#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Disjoint Set data structure with Path Compression and Union by Size
class DisjointSet {
    vector<int> parent, size, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Structure to cleanly represent a Graph Edge
struct Edge {
    int src, dest, weight;

    // Comparator operator to easily sort edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class KruskalsAlgorithm {
public:
    void findMST(int n, vector<Edge>& edges) {
        sort(edges.begin(), edges.end());

        DisjointSet ds(n);
        vector<Edge> mst;
        int totalMSTWeight = 0;

        // Step 2: Iterate through the sorted edges
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int wt = edge.weight;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                totalMSTWeight += wt;
                mst.push_back(edge);
                ds.unionBySize(u, v);
            }
            if (mst.size() == n - 1) break;
        }

        // Print Output Results
        cout << "--- Minimum Spanning Tree Edges ---" << endl;
        for (const auto& edge : mst) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        }
        cout << "Total MST Weight: " << totalMSTWeight << endl;
    }
};

// Driver Program
int main() {
    int n = 5; // Number of vertices (0 to 4)
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    KruskalsAlgorithm solver;
    solver.findMST(n, edges);

    return 0;
}