class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); // Tracks last index of each ASCII character
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            // If character was seen inside the current window, move left pointer
            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }

            // Update character's last seen position
            lastSeen[currentChar] = right;

            // Calculate max window size
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};