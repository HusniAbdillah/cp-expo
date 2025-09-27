#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void printBoard(vector<vector<int>>& board, int n, string action = "") {
    system("cls");
    cout << "N-Queens Problem (Backtracking)\n\n";
    cout << action << "\n\n";
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                cout << "\033[1;33mQ \033[0m";
            else if ((i + j) % 2 == 0)
                cout << "□ ";
            else
                cout << "■ "; 
        }
        cout << endl;
    }
    Sleep(500);
}

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;
            
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
            
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;
            
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col >= n) {
        printBoard(board, n, "Solusi ditemukan!");
        return true;
    }
    
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            printBoard(board, n, "Mencoba menempatkan Queen di posisi (" + to_string(i) + "," + to_string(col) + ")");
            
            if (solveNQueens(board, col + 1, n))
                return true;
                
            board[i][col] = 0;
            printBoard(board, n, "Backtracking - Menghapus Queen di posisi (" + to_string(i) + "," + to_string(col) + ")");
        }
    }
    
    return false;
}

int main() {
    int n;
    cout << "Masukkan ukuran papan (n): ";
    cin >> n;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    if (!solveNQueens(board, 0, n))
        cout << "\nTidak ada solusi untuk N-Queens dengan n = " << n << endl;
    else
        cout << "\nSolusi berhasil ditemukan!" << endl;
    
    return 0;
}