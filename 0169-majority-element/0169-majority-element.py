class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        ans=nums[0]
        f=1
        for i in range (1,len(nums)):
            if(nums[i]==ans):
                f+=1
            else:
                f-=1
            if f==0:
                ans=nums[i]
                f=1
        return ans