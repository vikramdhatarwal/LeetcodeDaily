class Solution {
public:
    int subArray_lessThanGoal(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0;
        int r=0;
        int odd=0;
        int ans=0;
        while(r<nums.size()){
            if(nums[r]%2==1){
                odd++;
            }
            if(odd<=goal){
                ans+=r-l+1;
                r++;
            }
            
            else{
                odd--;
                while(odd>=goal){
                    if(nums[l]%2==1){
                        odd--;
                    }
                    l++;
                }
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return    subArray_lessThanGoal(nums,k)-subArray_lessThanGoal(nums,k-1);
    }
};