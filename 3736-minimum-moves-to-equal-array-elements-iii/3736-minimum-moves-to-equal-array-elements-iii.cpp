class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxii=nums[0];
        for(int el: nums){
            maxii=max(maxii,el);
        }
        int ans=0;
        for(int el: nums){
            ans+= (maxii-el);
        }
        return ans;
    }
};