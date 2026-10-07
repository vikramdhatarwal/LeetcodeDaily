class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        k=0
        while(k<len(nums) and nums[k]!=val):
            k+=1
        for i in range(k+1,len(nums)):
            if(nums[i]!=val):
                nums[k]=nums[i]
                k+=1
        return k