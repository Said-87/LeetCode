#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // memo[i][j][len]: -1 = unvisited, 0 = false, 1 = true
    int memo[31][31][31];

    bool solve(const string& s1, const string& s2, int i, int j, int len) {
        if (memo[i][j][len] != -1) {
            return memo[i][j][len];
        }

        // Base case: strings are identical
        if (s1.compare(i, len, s2, j, len) == 0) {
            return memo[i][j][len] = 1;
        }

        // Frequency check pruning: if character counts don't match, false
        int count[26] = {0};
        for (int k = 0; k < len; ++k) {
            count[s1[i + k] - 'a']++;
            count[s2[j + k] - 'a']--;
        }
        for (int k = 0; k < 26; ++k) {
            if (count[k] != 0) {
                return memo[i][j][len] = 0;
            }
        }

        // Try every possible split length k (from 1 to len - 1)
        for (int k = 1; k < len; ++k) {
            // Case 1: No swap
            // s1[i..i+k-1] == s2[j..j+k-1] && s1[i+k..i+len-1] == s2[j+k..j+len-1]
            if (solve(s1, s2, i, j, k) && solve(s1, s2, i + k, j + k, len - k)) {
                return memo[i][j][len] = 1;
            }

            // Case 2: Swapped
            // s1[i..i+k-1] == s2[j+len-k..j+len-1] && s1[i+k..i+len-1] == s2[j..j+len-k-1]
            if (solve(s1, s2, i, j + len - k, k) && solve(s1, s2, i + k, j, len - k)) {
                return memo[i][j][len] = 1;
            }
        }

        return memo[i][j][len] = 0;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        memset(memo, -1, sizeof(memo));
        return solve(s1, s2, 0, 0, s1.length());
    }
};