class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary-search the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int left1 = (partition1 == 0)
                            ? INT_MIN
                            : nums1[partition1 - 1];

            int right1 = (partition1 == m)
                             ? INT_MAX
                             : nums1[partition1];

            int left2 = (partition2 == 0)
                            ? INT_MIN
                            : nums2[partition2 - 1];

            int right2 = (partition2 == n)
                             ? INT_MAX
                             : nums2[partition2];

            // Correct partition found
            if (left1 <= right2 && left2 <= right1) {
                // Odd total number of elements
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Even total number of elements
                return (
                    static_cast<double>(max(left1, left2)) +
                    static_cast<double>(min(right1, right2))
                ) / 2.0;
            }

            if (left1 > right2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }

        return 0.0;
    }
};