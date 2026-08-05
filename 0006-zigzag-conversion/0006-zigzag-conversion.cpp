class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        int direction = 1;

        for (char ch : s) {
            rows[currentRow] += ch;

            if (currentRow == 0) {
                direction = 1;
            } else if (currentRow == numRows - 1) {
                direction = -1;
            }

            currentRow += direction;
        }

        string result;

        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};