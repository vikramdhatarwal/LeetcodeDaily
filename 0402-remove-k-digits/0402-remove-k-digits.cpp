class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0";
        string ans="";
        stack<char> s;
        s.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(k>0 && !s.empty() && num[i]<s.top()){
                k--;
                s.pop();
               
            }
            s.push(num[i]);
        }
        while(k>0){
            s.pop();
            k--;
        }
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        int i=0;
        reverse(ans.begin(),ans.end());
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        return (ans.size() > 0) ? ans : "0";
    }
};