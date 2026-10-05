class Solution:
    def firstUniqChar(self, s: str) -> int:
        m={}
        for x in s:
            m[x]=m.get(x,0)+1
        for i in range(len(s)):
            if(m[s[i]]==1):
                return i
        return -1