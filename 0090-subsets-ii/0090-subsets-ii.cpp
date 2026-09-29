class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int index, vector<int>& current) {
        // Every current combination is a valid subset
        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > index && nums[i] == nums[i - 1])
                continue;

            // Include nums[i]
            current.push_back(nums[i]);

            solve(nums, i + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        solve(nums, 0, current);

        return result;
    }
};