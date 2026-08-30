class Solution {
    public boolean canJump(int[] nums) {
        int farthest = 0;

        for (int i = 0; i < nums.length; i++) {

            // If this index cannot be reached
            if (i > farthest) {
                return false;
            }

            // Update the farthest position we can reach
            farthest = Math.max(farthest, i + nums[i]);

            // We can already reach the last index
            if (farthest >= nums.length - 1) {
                return true;
            }
        }

        return true;
    }
}