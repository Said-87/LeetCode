class Solution {
private:
    void backtrack(const string& s, int start, int parts,
                   string ip, vector<string>& result) {
        int remaining = s.size() - start;
        int partsLeft = 4 - parts;

        // Each remaining part needs between 1 and 3 digits.
        if (remaining < partsLeft || remaining > partsLeft * 3)
            return;

        if (parts == 4) {
            if (start == s.size())
                result.push_back(ip);
            return;
        }

        int value = 0;

        for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
            // Allow "0", but reject "01", "00", etc.
            if (len > 1 && s[start] == '0')
                break;

            value = value * 10 + (s[start + len - 1] - '0');

            if (value > 255)
                break;

            string part = s.substr(start, len);

            backtrack(s, start + len, parts + 1,
                      ip + (parts == 0 ? "" : ".") + part,
                      result);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        if (s.size() < 4 || s.size() > 12)
            return result;

        backtrack(s, 0, 0, "", result);
        return result;
    }
};