#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dx [4] = {-1,1,0,0};
    int dy [4] = {0,0,-1,1};
    bool dfs(int row,int col,int index,vector<vector<char>>&board,string word,vector<vector<int>>&visited) {
        if(index == word.size())
        {
            return true;
        }
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || visited[row][col] || board[row][col] != word[index]){
            return false;
        }
        visited[row][col] = 1;
        for(int i = 0;i<4;i++){
            int nrow = dx[i] + row;
            int ncol = dy[i] + col;
            if(dfs(nrow,ncol,index+1,board,word,visited))
            {
                return true;
            }
        }
        visited[row][col] = 0;
        return false;
    }
public:
    // Function to check if the word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(dfs(i,j,0,board,word,visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha << sol.exist(board, "ABCCED") << endl; // true
    cout << boolalpha << sol.exist(board, "SEE") << endl;    // true
    cout << boolalpha << sol.exist(board, "ABCB") << endl;   // false
}
