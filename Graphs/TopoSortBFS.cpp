#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        
        // Directly use 'edges' instead of copying it to 'adj' to save memory
        vector<int> ans(n, 0);
        
        // Move the visited array OUTSIDE the loop. 
        // Re-allocating it inside the loop causes massive slow-downs.
        // Instead of true/false, we store the step number (1, 2, 3...) when we saw it.
        vector<int> visited(n, 0); 
        
        for (int i = 0; i < n; i++) {
            // OPTIMIZATION: If we already calculated the answer for this node 
            // from a previous path, skip it entirely!
            if (ans[i] > 0) continue; 
            
            queue<int> q;
            vector<int> path; // Keeps track of the nodes we visit in this specific run
            
            q.push(i);
            path.push_back(i);
            visited[i] = 1;
            int temp = 1;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                int it = edges[node];
                
                if (!visited[it]) {
                    q.push(it);
                    path.push_back(it); // Remember the order we visited them
                    temp++;
                    visited[it] = temp; // Store the step sequence number
                }
                else {
                    int cycle_start_step = visited[it];
                    int cycle_len = temp - cycle_start_step + 1;
                    
                    // Now distribute the correct answers to everything in our path
                    for (int j = 0; j < path.size(); j++) {
                        int curr_node = path[j];
                        int node_step = visited[curr_node];
                        
                        if (node_step < cycle_start_step) {
                            // Node is outside the cycle, leading into it
                            ans[curr_node] = (cycle_start_step - node_step) + cycle_len;
                        } else {
                            // Node is directly inside the cycle
                            ans[curr_node] = cycle_len;
                        }
                    }
                    break;
                }
            }
            
            // Cleanup: Reset the visited states for the nodes we just touched 
            // so the next iteration starts fresh, without re-allocating a whole vector.
            for (int node : path) {
                visited[node] = 0;
            }
        }
        
        return ans;
    }
};