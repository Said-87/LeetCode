class Solution {
    public boolean isNumber(String s) {
        boolean digitSeen = false;
        boolean dotSeen = false;
        boolean exponentSeen = false;
        boolean exponentDigitSeen = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            // Digit
            if (Character.isDigit(c)) {
                digitSeen = true;

                if (exponentSeen) {
                    exponentDigitSeen = true;
                }
            }

            // Decimal point
            else if (c == '.') {
                // Dot is not allowed after exponent
                // and only one dot is allowed
                if (dotSeen || exponentSeen) {
                    return false;
                }

                dotSeen = true;
            }

            // Exponent
            else if (c == 'e' || c == 'E') {
                // Exponent must:
                // 1. appear only once
                // 2. come after at least one digit
                if (exponentSeen || !digitSeen) {
                    return false;
                }

                exponentSeen = true;
                exponentDigitSeen = false;
            }

            // Sign
            else if (c == '+' || c == '-') {
                // Sign is valid only at the beginning
                // or immediately after e/E
                if (i != 0 && s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') {
                    return false;
                }
            }

            // Anything else is invalid
            else {
                return false;
            }
        }

        return digitSeen && exponentDigitSeen;
    }
}