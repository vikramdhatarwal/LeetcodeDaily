class Solution {
public:
    bool isValid(string s) {
        
        stack<char> s1;
        for(char ch : s){
            if(ch=='(' || ch=='{' || ch=='['){
                s1.push(ch);
            }
            else if(ch==')' && !s1.empty() && s1.top()=='('){
                s1.pop();
            }
            else if(ch=='}' && !s1.empty() && s1.top()=='{'){
                s1.pop();
            }
            else if(ch==']' && !s1.empty() && s1.top()=='['){
                s1.pop();
            }
            else return false;
        }
        if(s1.size()!=0) return false;
        return true;
    }
};