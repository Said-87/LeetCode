class Solution {
    public int mySqrt(int x) {
        // Handle base cases where x is 0 or 1
        if (x < 2) {
            return x;
        }
        
        int left = 2;
        int right = x / 2;
        
        while (left <= right) {
            // Prevent integer overflow when calculating mid
            int mid = left + (right - left) / 2;
            
            // Cast to long to prevent overflow when squaring
            long squared = (long) mid * mid; 
            
            if (squared == x) {
                return mid;
            } else if (squared > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // When the loop ends, 'right' will hold the truncated square root
        return right;
    }
}