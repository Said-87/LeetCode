#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            if (seen.find(needed) != seen.end()) {
                return {seen[needed], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};