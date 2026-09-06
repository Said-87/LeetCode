class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] represents the minimum operations to convert 
        // word1.substring(0, i) to word2.substring(0, j)
        int[][] dp = new int[m + 1][n + 1];
        
        // Base cases: converting to/from an empty string
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i; // requires 'i' deletions
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j; // requires 'j' insertions
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    // Characters match, inherit the cost from the previous state
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Characters differ, find the minimum of the three operations
                    int replace = dp[i - 1][j - 1];
                    int delete = dp[i - 1][j];
                    int insert = dp[i][j - 1];
                    
                    dp[i][j] = 1 + Math.min(replace, Math.min(delete, insert));
                }
            }
        }
        
        return dp[m][n];
    }
}