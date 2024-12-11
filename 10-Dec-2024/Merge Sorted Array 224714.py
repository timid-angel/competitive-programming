# Problem: Merge Sorted Array
(Easy) - https://leetcode.com/problems/merge-sorted-array/

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        c = len(nums1) - 1
        n1, n2 = m-1, n-1
        while n1 >= 0 and n2 >= 0:
            if nums1[n1] >= nums2[n2]:
                nums1[c] = nums1[n1]
                n1 -= 1
            else:
                nums1[c] = nums2[n2]
                n2 -= 1

            c -= 1

        while n1 >= 0:
            nums1[c] = nums1[n1]
            n1 -= 1
            c -= 1
        
        while n2 >= 0:
            nums1[c] = nums2[n2]
            n2 -= 1
            c -= 1
