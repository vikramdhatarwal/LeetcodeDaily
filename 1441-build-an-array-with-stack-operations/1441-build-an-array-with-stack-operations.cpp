class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=0;
        stack<int> s;
        vector<string> ans;
        for(int x=1;x<=n;x++){
           
            if(i<target.size()){
                s.push(x);
                ans.push_back("Push");
            }
            
            if(i<target.size() && s.top()!=target[i]){
                s.pop();
                ans.push_back("Pop");
            }
            if(!s.empty() && i<target.size() && s.top()==target[i]){
                i++;
            }
        }
        return ans;
    }
};