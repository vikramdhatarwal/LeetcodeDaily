class Solution {
public:
    int subArray_lessThanGoal(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0;
        int r=0;
        int sum=0;
        int ans=0;
        while(r<nums.size()){
            if(sum+nums[r]<=goal){
                ans+=r-l+1;
                sum+=nums[r];
                r++;
            }
            else{
                while(sum>=goal){
                    sum-=nums[l];
                    l++;
                }
            }
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subArray_lessThanGoal(nums,goal)-subArray_lessThanGoal(nums,goal-1);
    }
};