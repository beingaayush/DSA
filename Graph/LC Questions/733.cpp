// Problem Statement:
// ou are given a 2D integer matrix image, where image[row][col] represents the color of a pixel.
// You are also given:
// sr → starting row
// sc → starting column
// color → new color
// Starting from (sr, sc), you need to change the color of the starting pixel and every connected pixel having the same original color to color.
// Two pixels are considered connected if they share a side:
//        Up
//        ↑
// Left ← X → Right
//        ↓
//       Down
// Return the modified image.
// eg: image =
// [
//  [1,1,1],
//  [1,1,0],
//  [1,0,1]
// ]

// sr = 1
// sc = 1
// color = 2

// Starting pixel:
// 1 1 1
// 1 X 0
// 1 0 1

// The connected pixels having the same original color 1 become 2:
// 2 2 2
// 2 2 0
// 2 0 1
// ------------------------------------------------------------------------------------------------------------------

// Core idea:  Use DFS on the 2D grid.
// Steps  :-
// Get the starting pixel's original color:
// int originalColor = image[sr][sc];
// If originalColor == color, return the image because nothing needs to change.
// Start DFS from (sr, sc).

// In DFS:
// If the cell is out of bounds, return.
// If its color is not originalColor, return.
// Otherwise, change it to color.
// Recursively visit its 4 neighbours.

// The most important condition :-
// if (image[row][col] != originalColor)
//     return;
// This prevents DFS from entering cells that do not belong to the original connected region.

// Concept: Grid Traversal + DFS + 4 Directions
// Time: O(m × n)
// Space: O(m × n) worst case due to recursion.


#include <bits/stdc++.h>
using namespace std;
class Solution{
private:
    void dfs(vector<vector<int>>& image, int row, int col, int originalColor, int color){
        int rows = image.size();
        int cols = image[0].size();

        // out of boundary
        if(row < 0 || row >= rows || col < 0 || col >= cols) return;

        // out of DFS limitation bound
        if(image[row][col] != originalColor) return;

        // change color
        image[row][col] = color;

        // explore all 4 directions
        dfs(image, row-1, col, originalColor, color);     //up
        dfs(image, row+1, col, originalColor, color);    //down
        dfs(image, row, col-1, originalColor, color);    //left
        dfs(image, row, col+1, originalColor, color);    //right

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;    // If both colors are same, nothing to change

        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};
