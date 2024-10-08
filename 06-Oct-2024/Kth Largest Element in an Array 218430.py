# Problem: Kth Largest Element in an Array - https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nm = [-x for x in nums]
        heapify(nm)
        for i in range(k-1):
            heappop(nm)
        
        return -heappop(nm)
        