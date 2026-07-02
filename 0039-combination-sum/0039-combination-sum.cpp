class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target,int idx,vector<int>res){
        if (idx>=candidates.size()){
            if(target==0){
                ans.push_back(res);
            }
            return;
        }
        
        if(target>=candidates[idx]){
            res.push_back(candidates[idx]);
            helper(candidates,target-candidates[idx],idx,res);
            res.pop_back();
        }
        helper(candidates,target,idx+1,res);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        helper(candidates,target,0,res);
        return ans;
    }
};