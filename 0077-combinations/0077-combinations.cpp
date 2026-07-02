class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>  &curr,int i,int k,int n){
        
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        if(i>n){
            return;
        }
        curr.push_back(i);
        helper(curr,i+1,k,n);
        curr.pop_back();
        helper(curr,i+1,k,n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        helper(curr,1,k,n);
        return ans;
    }
};