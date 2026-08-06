#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

bool isSafeRow(vector<vector<char>>&board,int row,char c)
{
    int n = board[0].size();
    for(int i = 0;i<n;i++)
    {
        if(board[row][i] == c)
        {
            return false;
        }
    }
    return true;
}

bool isSafeCol(vector<vector<char>>&board,int col,char c)
{
    int n = board.size();
    for(int i = 0;i<n;i++)
    {
        if(board[i][col] == c)
        {
            return false;
        }
    }
    return true;
}
bool isSafeBox(vector<vector<char>>&board,int row,int col,char c)
{
    int rowstart = 3 * (row/3);
    int colstart = 3*(col/3);
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            if(board[rowstart+i][colstart+j] == c)
            {
                return false;
            }
        }
    }
    return true;
}
// Function to check if placing character c at board[row][col] is valid
bool isValid(int row, int col, char c,vector<vector<char>> &board) {
    if(!isSafeRow(board,row,c)){
        return false;
    }
    if(!isSafeCol(board,col,c)){
        return false;
    }
    if(!isSafeBox(board,row,col,c))
    {
        return false;
    }
    return true;
}

// Recursive function to solve Sudoku using backtracking
bool solveSudoku(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(board[i][j] == '.')
            {
                for(char ch = '1';ch<='9';ch++)
                {
                    if(isValid(i,j,ch,board))
                    {
                        board[i][j] = ch;
                        if(solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
};

int main() {
    // Initialize the Sudoku board with given values and '.' for blanks
    vector<vector<char>> board {
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };


    Solution sol;
    sol.solveSudoku(board);

    // Print the solved Sudoku board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
