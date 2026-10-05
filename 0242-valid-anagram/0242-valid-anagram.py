class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        m1={}
        m2={}
        for x in s:
            m1[x]=m1.get(x,0)+1
        for x in t:
            m2[x]=m2.get(x,0)+1

        for key in m1:
            if(m1[key]!=m2.get(key, 0)):
                return False
        return True
