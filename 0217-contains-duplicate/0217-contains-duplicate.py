class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        s=set(nums)
        if len(s)!=len(nums):
            return True
        return False