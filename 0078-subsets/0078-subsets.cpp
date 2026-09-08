#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }

private:
    void backtrack(int start, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Every combination we form along the way is a valid subset
        result.push_back(current);
        
        // Iterate through the remaining possible elements
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);                  // Choose the number
            backtrack(i + 1, nums, current, result);     // Explore adding more numbers
            current.pop_back();                          // Undo the choice (backtrack)
        }
    }
};