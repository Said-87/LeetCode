class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int num = 1;

        while (top <= bottom && left <= right) {

            // Fill top row
            for (int col = left; col <= right; col++) {
                matrix[top][col] = num++;
            }
            top++;

            // Fill right column
            for (int row = top; row <= bottom; row++) {
                matrix[row][right] = num++;
            }
            right--;

            // Fill bottom row
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }

            // Fill left column
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    matrix[row][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
}