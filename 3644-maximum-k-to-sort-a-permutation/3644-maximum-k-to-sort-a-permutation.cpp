class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1 || is_sorted(nums.begin(),nums.end())) return 0;
        int ans=-1;
        for (int i=0;i<n;i++){
            if(nums[i]!=i){
                ans=ans&nums[i];
            }
        }
        return ans;
    }
};