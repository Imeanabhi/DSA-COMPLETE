#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c,int originalColor, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        

        if (r >= 0 && r < rows && c >=0 && c < cols && image[r][c] == originalColor) {
    
        image[r][c] = newColor;

        // Recursive calls for 4-directional neighbors
        dfs(image, r + 1, c,originalColor, newColor); // Down
        dfs(image, r - 1, c,originalColor, newColor); // Up
        dfs(image, r, c + 1,originalColor, newColor); // Right
        dfs(image, r, c - 1,originalColor, newColor); // Left
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
            dfs(image, sr, sc,originalColor, newColor);
        
        return image;
    }
};

int main() {
    Solution sol;

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
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "\nAfter Recursive Flood Fill:" << endl;
    for (const auto& row : result) {
        for (int pixel : row) cout << pixel << " ";
        cout << endl;
    }

    return 0;
}