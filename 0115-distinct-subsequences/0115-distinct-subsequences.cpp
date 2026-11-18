
class Solution {
public:
    int numDistinct(string s, string t) {

        int m = s.length();
        int n = t.length();

        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));

        // Empty t can be formed in exactly one way
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // Characters match
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }

                // Characters don't match
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};
