class Solution {
public:
    void helper(int cntO, int cntC,string &curr, vector<string> &ans){
        if(cntO<0 || cntC<0) return;
        if(cntO==0 && cntC==0){
            ans.push_back(curr);
        }
        if(cntO>0){
            curr.push_back('(');
            helper(cntO-1,cntC,curr,ans);
            curr.pop_back();
        }
        if(cntC>cntO){
              curr.push_back(')');
            helper(cntO,cntC-1,curr,ans);
            curr.pop_back();
        }
      
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        helper(n,n,curr,ans);
        return ans;
    }
};