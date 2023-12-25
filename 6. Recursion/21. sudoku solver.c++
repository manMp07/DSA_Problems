#include <bits/stdc++.h>
using namespace std;

//Que.- Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square
//      matrix (grid[][]), the task is to find a solved Sudoku. For simplicity, you
//      may assume that there will be only one unique solution.
//      Zeros in the grid indicates blanks, which are to be filled with some number
//      between 1-9. You can not replace the element in the cell which is not blank.

// Time : O(9^K) ; K = number of empty cells
// Space : O(9*9) = O(1)

bool isSafe(int row, int col, int val, vector<vector<int>> sudoku) {

    for(int i = 0; i < 9; i++) {
        // row check
        if(sudoku[i][col] == val)
            return false;
        
        if(sudoku[row][i] == val)
            return false;

        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &sudoku) {

    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            if(sudoku[row][col] == 0) {
                
                for(int i = 1; i <= 9; i++) {

                    if(isSafe(row, col, i, sudoku)){
                        sudoku[row][col] = i;
                        bool nextSolution = solve(sudoku);
                        
                        if(nextSolution)
                            return true;
                        else
                            sudoku[row][col] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
}