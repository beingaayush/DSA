// Problem Statement:
// You are given an integer n.
// Place n queens on an n × n chessboard such that:
// No two queens attack each other.
// Rules of attack
// A queen can attack: | same row | same column | both diagonals
// Task -
// Return all distinct solutions.
// Each solution should be represented as a board of size n x n using:
// 'Q' → queen | '.' → empty cell

// Core idea:
// Place 1 queen per column
// For each column → try all rows
// Place only if safe:
// row unused
// / lowerdiag → row + col
// \ upperdiag → n - 1 + col - row
// If placed → recurse to next column
// If stuck → backtrack (undo)
// If col == n → store solution
// Try → Recurse → Undo → Repeat

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        void solve(int col, int n, vector<vector<string>> &ans, vector<string> &board, vector<int> leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal)    
        {
            //base case (all columns filled)
            if(col == n){
                ans.push_back(board);
                return;
            }
            
            // try placing queen in every row of current column
            for(int row=0; row<n; row++){
                if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0){
                    
                    //place queens
                    board[row][col] = 'Q';
                    // mark row and diagonals as occupied
                    leftRow[row] = 1;
                    lowerDiagonal[row + col] = 1;
                    upperDiagonal[n - 1 + col - row] = 1;

                    // move to next column
                    solve(col + 1, n, ans, board, leftRow, lowerDiagonal, upperDiagonal);

                    //Backtrack
                    board[row][col] = '.';    //remove queen
                    //unMark
                    leftRow[row]  = 1;
                    lowerDiagonal[row + col] = 1;
                    upperDiagonal[n - 1 + col - row] = 1;
                }
            }
        }

        vector<vector<string>> solveNQueens(int n){
            vector<vector<string>> ans;
            vector<string> board(n, string(n, '.'));     //create empty board

            //helper arrays for safety check (0/1)
            vector<int> leftRow(n, 0);
            vector<int> lowerDiagonal(2 * n - 1);
            vector<int> upperDiagonal(2 * n - 1);
            solve(0, n, ans, board, leftRow, lowerDiagonal, upperDiagonal);

            return ans;
        }
};