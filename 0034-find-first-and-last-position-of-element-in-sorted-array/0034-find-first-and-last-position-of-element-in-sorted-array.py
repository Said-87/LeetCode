class Solution:
    def searchRange(self, nums, target):
        def find_first():
            left, right = 0, len(nums) - 1
            result = -1

            while left <= right:
                mid = left + (right - left) // 2

                if nums[mid] == target:
                    result = mid
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1

            return result

        def find_last():
            left, right = 0, len(nums) - 1
            result = -1

            while left <= right:
                mid = left + (right - left) // 2

                if nums[mid] == target:
                    result = mid
                    left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1

            return result

        return [find_first(), find_last()]