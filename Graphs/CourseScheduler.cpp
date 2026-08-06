#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Checks if it is possible to finish all courses given the prerequisites.
     * This is essentially checking if the directed graph is a Directed Acyclic Graph (DAG).
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Create Adjacency List and Indegree Array
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pair : prerequisites) {
            int course = pair[0];
            int pre = pair[1];
            // Edge direction: Prerequisite -> Course
            adj[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int processedCount = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processedCount++;

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return processedCount == numCourses;
    }
};

int main() {
    Solution sol;

    
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    if (sol.canFinish(numCourses, prerequisites)) {
        cout << "Result: true (All courses can be finished)" << endl;
    } else {
        cout << "Result: false (Cycle detected, cannot finish courses)" << endl;
    }

    // Additional Test Case: A cycle 0 -> 1 -> 0
    vector<vector<int>> cyclePrereqs = {{1, 0}, {0, 1}};
    if (!sol.canFinish(2, cyclePrereqs)) {
        cout << "Cycle Test: false No Cycle Detected" << endl;
    }

    return 0;
}