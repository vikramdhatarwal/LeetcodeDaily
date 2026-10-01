class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
      
        m={}
        for i in range (len(nums)):
            if target-nums[i] in m:
                return [i,m[target-nums[i]]]

            else:
                m[nums[i]]=i
