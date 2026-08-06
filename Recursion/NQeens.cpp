#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafeRow(int row,int col,vector<string>&board)
    {
        while(col>=0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }
        return true;
    }
    bool isSafeUpperDiagonal(int row,int col,vector<string>&board)
    {
        while(row>=0 && col>=0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        return true;
    }
    bool isSafeLowerDiagonal(int row,int col,vector<string>&board)
    {
        while(row<board.size() && col>=0){
        if(board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
    }
    bool isSafe(int row,int col,vector<string>&board)
    {
        int x = row;
        int y = col;
        if(!isSafeRow(row,col,board))
        {
            return false;
        }
        col = y;
        if(!isSafeUpperDiagonal(row,col,board))
        {
            return false;
        }
        row = x;
        col = y;
        if(!isSafeLowerDiagonal(row,col,board))
        {
            return false;
        }
        return true;
    }
    void recursion(int col,int n,vector<string>&board,vector<vector<string>>&ans)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++)
        {
            if(isSafe(row,col,board))
            {
                board[row][col] = 'Q';
                recursion(col+1,n,board,ans);
                board[row][col] = '.';
            }
            
        }
    }
    // Main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        recursion(0, n, board,ans);
        return ans;
    }
};

int main() {
    Solution obj;
    int n = 6;
    vector<vector<string>> res = obj.solveNQueens(n);
    for (auto& board : res) {
        for (auto& row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }
    return 0;
}
