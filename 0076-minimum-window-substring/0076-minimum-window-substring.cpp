#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Array to store the count of required characters. 128 covers all ASCII letters.
        vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }
        
        int counter = t.size(); // Total characters required to match
        int begin = 0, end = 0;
        int min_len = INT_MAX, head = 0;
        
        while (end < s.size()) {
            // If the character at 'end' is in t, decrease the required counter
            if (map[s[end]] > 0) {
                counter--;
            }
            // Decrease the character's count in the map and expand the window
            map[s[end]]--;
            end++;
            
            // When counter reaches 0, the current window contains all characters from t
            while (counter == 0) {
                // Update the minimum window size and its starting position
                if (end - begin < min_len) {
                    min_len = end - begin;
                    head = begin;
                }
                
                // Shrink the window from the left
                map[s[begin]]++;
                // If a required character is removed, the window becomes invalid
                if (map[s[begin]] > 0) {
                    counter++;
                }
                begin++;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(head, min_len);
    }
};