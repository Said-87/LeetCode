import java.util.*;

class Solution {

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();

        char[][] board = new char[n][n];

        // Fill the board with '.'
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }

        backtrack(0, n, board, result);

        return result;
    }

    private void backtrack(
            int row,
            int n,
            char[][] board,
            List<List<String>> result) {

        // All queens have been placed
        if (row == n) {
            List<String> solution = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                solution.add(new String(board[i]));
            }

            result.add(solution);
            return;
        }

        // Try placing a queen in every column
        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, n, board)) {

                // Place queen
                board[row][col] = 'Q';

                // Move to next row
                backtrack(row + 1, n, board, result);

                // Remove queen (backtrack)
                board[row][col] = '.';
            }
        }
    }

    private boolean isSafe(
            int row,
            int col,
            int n,
            char[][] board) {

        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        int r = row - 1;
        int c = col - 1;

        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        // Check upper-right diagonal
        r = row - 1;
        c = col + 1;

        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }

        return true;
    }
}