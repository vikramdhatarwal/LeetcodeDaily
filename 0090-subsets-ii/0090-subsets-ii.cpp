class Solution {
public:

    void helper(int idx,vector<int>& nums,vector<vector<int>> &ans, vector<int> &curr){
    
        ans.push_back(curr);
       
        
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            helper(i+1,nums,ans,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,curr);
        return ans;
    }
};