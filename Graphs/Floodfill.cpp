#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if(originalColor == newColor) return image;
    image[sr][sc] = newColor;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    queue<pair<int,int>>q;
    q.push({sr,sc});
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++)
        {
            int nx = dx[i] + row;
            int ny = dy[i] + col;
            if(nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size() && image[nx][ny] == 1)
            {
                image[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
    return image;
    }
};


int main() {
    Solution sol;


    // Initial: [[1,1,1],[1,1,0],[1,0,1]]
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    cout << "Original Image:" << endl;
    for (const auto& row : image) {
        for (int pixel : row) cout << pixel << " ";
        cout << endl;
    }

    // Process the flood fill
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "\nAfter Flood Fill (at 1,1 with color 2):" << endl;
    for (const auto& row : result) {
        for (int pixel : row) cout << pixel << " ";
        cout << endl;
    }

    return 0;
}