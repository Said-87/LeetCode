class Solution {

    public int totalNQueens(int n) {
        return backtrack(0, n, new boolean[n],
                         new boolean[2 * n - 1],
                         new boolean[2 * n - 1]);
    }

    private int backtrack(
            int row,
            int n,
            boolean[] cols,
            boolean[] diag1,
            boolean[] diag2) {

        // All queens have been placed
        if (row == n) {
            return 1;
        }

        int count = 0;

        for (int col = 0; col < n; col++) {

            // Diagonal indexes
            int d1 = row - col + n - 1;
            int d2 = row + col;

            // If position is already attacked
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            // Place queen
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            // Move to next row
            count += backtrack(row + 1, n, cols, diag1, diag2);

            // Remove queen (backtrack)
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }

        return count;
    }
}