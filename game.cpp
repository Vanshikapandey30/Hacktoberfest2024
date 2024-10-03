#include<bits/stdc++.h>
using namespace std;

#define EASY 3
#define HARD 9

class SudokuSolver {
public:
    int size;
    vector<vector<int>> board;

    SudokuSolver(int mode) {
        size = (mode == EASY) ? EASY : HARD;
        board.resize(size, vector<int>(size, 0)); 
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout<<board[i][j]<<" ";
            }
            cout << endl;
        }
    }
};
bool isValid(vector<vector<int>> &board, int row, int col, int num, int size) {
    for (int i = 0; i < size; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    int subGridSize=(size == EASY) ? 1 : 3; 
    int subRowStart=(row/subGridSize)*subGridSize;
    int subColStart=(col/subGridSize)*subGridSize;

    for (int i = 0;i<subGridSize;i++) {
        for (int j = 0; j < subGridSize; j++) {
            if (board[subRowStart + i][subColStart + j]==num) {
                return false;
            }
        }
    }

    return true;
}
// Backtracking function to solve the Sudoku
bool solveSudoku(vector<vector<int>> &board, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            //finding empty elements
            if (board[row][col] == 0) {
                // Try all possible numbers
                for (int num = 1; num <= size; num++) {
                    if (isValid(board, row, col, num, size)) {
                        board[row][col] = num;
                        if (solveSudoku(board, size)) {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}
int main() {
    int mode;
    cout << "Choose mode: 1 for Easy (3x3), 2 for Hard (9x9): ";
    cin >> mode;
    
    int selectedMode = (mode == 1) ? EASY : HARD;
    SudokuSolver solver(selectedMode);

    cout << "Enter Sudoku puzzle (row by row, 0 for empty):" << endl;
    for (int i = 0; i < solver.size; i++) {
        for (int j = 0; j < solver.size; j++) {
            cin >> solver.board[i][j];
        }
    }
    if (solveSudoku(solver.board, solver.size)) {
        cout << "Solved Sudoku:" << endl;
        solver.printBoard();
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}

