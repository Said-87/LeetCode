import java.util.*;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {

        List<String> result = new ArrayList<>();
        int i = 0;

        while (i < words.length) {

            // Find how many words can fit in this line
            int j = i;
            int lineLength = 0;

            while (j < words.length) {

                int wordLength = words[j].length();

                // At least one space is needed before every word except the first
                int needed = lineLength + wordLength + (j > i ? 1 : 0);

                if (needed > maxWidth) {
                    break;
                }

                lineLength = needed;
                j++;
            }

            int wordCount = j - i;
            boolean lastLine = (j == words.length);

            StringBuilder line = new StringBuilder();

            // Last line or line with only one word -> left justified
            if (wordCount == 1 || lastLine) {

                for (int k = i; k < j; k++) {
                    line.append(words[k]);

                    if (k < j - 1) {
                        line.append(" ");
                    }
                }

                // Add remaining spaces at the end
                while (line.length() < maxWidth) {
                    line.append(" ");
                }

            } else {

                // Total spaces that need to be distributed
                int totalSpaces = maxWidth;

                for (int k = i; k < j; k++) {
                    totalSpaces -= words[k].length();
                }

                // Number of gaps between words
                int gaps = wordCount - 1;

                // Minimum spaces per gap
                int spacesPerGap = totalSpaces / gaps;

                // Extra spaces that need to go to the leftmost gaps
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {

                    line.append(words[k]);

                    if (k < j - 1) {

                        int spaces = spacesPerGap;

                        // Left gaps get one extra space
                        if (k - i < extraSpaces) {
                            spaces++;
                        }

                        for (int s = 0; s < spaces; s++) {
                            line.append(" ");
                        }
                    }
                }
            }

            result.add(line.toString());

            // Move to the next line
            i = j;
        }

        return result;
    }
}