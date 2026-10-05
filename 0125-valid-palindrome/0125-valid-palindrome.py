class Solution:
    def isPalindrome(self, s: str) -> bool:
        p= s.lower()
        l=0
        r= len(p)-1
        while(l<r):
            if(p[l].isalnum() and p[r].isalnum()):
                if(p[l]!=p[r]):
                    return False
                l+=1
                r-=1
            elif (not p[l].isalnum()):
                l+=1
            elif (not p[r].isalnum()):
                r-=1
            
                
        return True