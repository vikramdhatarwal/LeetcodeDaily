class Solution:
    def isValid(self, s: str) -> bool:
        st=[]
        for ch in s:
            if(ch=='(' or ch=='{' or ch=='['):
                st.append(ch)
            else:
                if(len(st)==0):
                    return False
                op=st.pop()
                if(op=='(' and ch==')'):
                    continue
                elif(op=='{' and ch=='}'):
                    continue
                elif(op=='[' and ch==']'):
                    continue
                else:
                    return False
        if(len(st)!=0):
            return False
        return True
                    
