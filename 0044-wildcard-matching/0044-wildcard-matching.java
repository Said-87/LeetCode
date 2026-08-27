class Solution {
    public boolean isMatch(String s, String p) {
        int i = 0;              // pointer for s
        int j = 0;              // pointer for p

        int star = -1;          // position of last '*'
        int match = 0;          // position in s matched by '*'

        while (i < s.length()) {

            // Case 1: Characters match or pattern has '?'
            if (j < p.length() &&
                (p.charAt(j) == '?' || p.charAt(j) == s.charAt(i))) {

                i++;
                j++;
            }

            // Case 2: We found '*'
            else if (j < p.length() && p.charAt(j) == '*') {

                star = j;
                match = i;

                // Initially let '*' match empty
                j++;
            }

            // Case 3: Mismatch, but we have a previous '*'
            else if (star != -1) {

                // Let '*' match one more character
                j = star + 1;
                match++;
                i = match;
            }

            // Case 4: Mismatch and no '*' available
            else {
                return false;
            }
        }

        // Remaining pattern characters must all be '*'
        while (j < p.length() && p.charAt(j) == '*') {
            j++;
        }

        return j == p.length();
    }
}