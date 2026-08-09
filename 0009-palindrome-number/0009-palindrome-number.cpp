class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) {
            return false;
        }

        // Numbers ending in 0 cannot be palindromes,
        // except the number 0 itself
        if (x != 0 && x % 10 == 0) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse only half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Even digits: x == reversedHalf
        // Odd digits:  x == reversedHalf / 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};