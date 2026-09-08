#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        // Base case: the combination is complete
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        // Optimization/Pruning: 
        // Stop the loop if there aren't enough numbers left to fill 'current' to size 'k'
        int limit = n - (k - current.size()) + 1;
        
        for (int i = start; i <= limit; ++i) {
            current.push_back(i);                      // Choose the number
            backtrack(i + 1, n, k, current, result);   // Explore further
            current.pop_back();                        // Undo the choice (backtrack)
        }
    }
};