class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        m={}
        for i in range (len(nums)):
            t=target-nums[i]
            if t in m:
                return [i,m[t]]
            else:
                m[nums[i]]=i
        return [-1,-1]