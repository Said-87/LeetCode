class Solution {
    public int climbStairs(int n) {
        // Base cases: 1 step has 1 way, 2 steps have 2 ways
        if (n <= 2) {
            return n;
        }
        
        int prev2 = 1; // Ways to reach step 1
        int prev1 = 2; // Ways to reach step 2
        
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
}