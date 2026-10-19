class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;
        for(char ch : s){
            
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else if(st.empty()) ans++;
            else if(ch==')'){
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
            else if(ch=='}'){
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
            else if(ch==']'){
                if(st.top()=='['){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
        }
        ans+=st.size();
        return ans;
    }
};