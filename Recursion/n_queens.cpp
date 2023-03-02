//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.


class Solution {
public:
     bool isSafe(int row, int col, vector<string> &board, int n)
    {
        // Upper Diagonal Check
        int dupRow = row;
        int dupCol = col;
        while(row>=0 && col>=0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        // Left Side Row check
        row = dupRow;
        col = dupCol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        // Lower Diagonal Check
        row = dupRow;
        col = dupCol;
        while(row<n && col>=0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<vector<string>> &res, vector<string> &board, int n)
    {
        if(col == n)
        {
            res.push_back(board);
            return;
        }
        for(int row=0; row<n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col+1, res, board, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
        {
            board[i] = s;
        }
        solve(0, res, board, n);
        return res;
    }
};
