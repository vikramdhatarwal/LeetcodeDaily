class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int ans=0;
        while(r<nums.size()){
            if(nums[r]==1){
                r++;
            }
            else if(nums[r]==0 && k>0){
                r++;
                k--;
            }
            else{
                ans=max(ans,r-l);
                while(k==0){
                    if(nums[l]==0){
                        k++;
                    }
                    l++;
                }
            }
        }
        ans=max(ans,r-l);
        return ans;
    }
};