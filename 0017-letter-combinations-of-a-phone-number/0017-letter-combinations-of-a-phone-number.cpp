class Solution {
public:
    vector<string> mp = {"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void helper(int idx,vector<string> &ans, string &curr,string &digits){
       
        if(curr.size()==digits.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<mp[digits[idx]-'0'].size();i++){
            curr.push_back(mp[digits[idx]-'0'][i]);
            helper(idx+1,ans,curr,digits);
            curr.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr="";
        helper(0,ans,curr,digits);
        return ans;
    }
};