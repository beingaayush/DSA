// Problem Statement:
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Core Idea: Empty cell dhundo
// '1' → '9' try karo
// Check in O(1):

// rowUsed[row][num]
// colUsed[col][num]
// boxUsed[box][num]
// Valid → place + mark
// Recurse
// Fail → undo (backtrack)
// One-line:- Try → check (O(1)) → place → recurse → undo if fail

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int getBoxIndex(int row, int col){
            return (row/3) * 3 + (col/3);
        }

        bool solve(vector<vector<char>> &board){
            for(int row=0; row<9; row++){
                for(int col=0; col<9; col++){
                    //empty cell
                    if(board[row][col] == '.'){
                        for(char ch='1'; ch<'9'; ch++){
                            int num = ch - '0';
                            int box = getBoxIndex(row, col);

                            if(
                                rowUsed[row][num] == 0 &&
                                colUsed[col][num] == 0 &&
                                boxUsed[box][num] == 0
                            ){
                                //place
                                board[row][col] = ch;
                                rowUsed[row][num] = 1;
                                colUsed[col][num] = 1;
                                boxUsed[box][num] = 1;

                                if(solve(board)) return true;

                                //backtrack
                                board[row][col] = '.';
                                rowUsed[row][num] = 0;
                                colUsed[col][num] = 0;
                                boxUsed[box][num] = 0;
                            }
                        }
                        return false;   //no number fits here
                    }
                }
            }
            return true;  //board solved
        }

        vector<vector<int>> rowUsed, colUsed, boxUsed;
        void solveSudoku(vector<vector<char>> &board){
            rowUsed.assign(9, vector<int>(10, 0));
            colUsed.assign(9, vector<int>(10, 0));
            boxUsed.assign(9, vector<int>(10, 0));

            // mark already filled cells
            for(int row=0; row<9; row++){
                for(int col=0; col<9; col++){
                    if(board[row][col] != '.'){
                        int num = board[row][col] - '0';
                        int box = getBoxIndex(row, col);

                        rowUsed[row][num] = 1;
                        colUsed[col][num] = 1;
                        boxUsed[box][num] = 1;
                    }
                }
            }
            solve(board);
        }
};