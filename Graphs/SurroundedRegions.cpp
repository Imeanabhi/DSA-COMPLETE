#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& mat) {
        if (mat.empty()) return;
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // 1. Identify all boundary 'O's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (mat[i][j] == 'O') {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // 2. BFS to mark all 'O's connected to boundaries
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = row + dx[i];
                int ny = col + dy[i];

                // Added !visited[nx][ny] here to prevent infinite/redundant loops
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] && mat[nx][ny] == 'O') {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        // 3. Flip 'O's that were NOT reachable from the boundary
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    Solution obj;
    obj.solve(mat);

    for (auto row : mat) {
        for (char cell : row) cout << cell << " ";
        cout << "\n";
    }

    return 0;
}