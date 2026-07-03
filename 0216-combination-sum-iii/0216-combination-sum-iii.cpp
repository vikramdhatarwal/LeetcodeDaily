class Solution {
public:
    void helper(int n, vector<int> &curr, vector<vector<int>> &ans ,int k,int i){
        
        if(n==0 && curr.size()==k){
            ans.push_back(curr);
            return;
        }
        if(i>9 || n<0 || curr.size()>=k) return;
        
        curr.push_back(i);
        helper(n-i,curr,ans,k,i+1);
        curr.pop_back();
        helper(n,curr,ans,k,i+1);
    
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(n,curr,ans,k,1);
        return ans;
    }
};