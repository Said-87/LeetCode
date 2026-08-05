class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            // Odd-length palindrome
            expandFromCenter(s, i, i, start, maxLength);

            // Even-length palindrome
            expandFromCenter(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void expandFromCenter(
        const string& s,
        int left,
        int right,
        int& start,
        int& maxLength
    ) {
        while (
            left >= 0 &&
            right < static_cast<int>(s.size()) &&
            s[left] == s[right]
        ) {
            int currentLength = right - left + 1;

            if (currentLength > maxLength) {
                start = left;
                maxLength = currentLength;
            }

            left--;
            right++;
        }
    }
};