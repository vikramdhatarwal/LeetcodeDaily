class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        ans=strs[0]
        for s in strs:
            i=0
            while(i<min(len(ans),len(s)) and ans[i]==s[i]):
                i+=1
            ans=ans[:i]
        return ans
