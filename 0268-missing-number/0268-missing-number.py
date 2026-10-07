class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n=len(nums)
        total= (n)*(n+1)/2
        sum=0
        for x in nums:
            sum+=x
        return int(total-sum)