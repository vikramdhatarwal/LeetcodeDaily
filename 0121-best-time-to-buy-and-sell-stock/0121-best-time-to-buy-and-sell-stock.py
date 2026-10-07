class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        maxi=prices[-1]
        ans=0
        
        i=len(prices)-2
        while(i>=0):
            if(prices[i]<maxi):
                ans=max(ans,maxi-prices[i])
                i-=1
            else:
                maxi=prices[i] 
                i-=1 
        return ans
