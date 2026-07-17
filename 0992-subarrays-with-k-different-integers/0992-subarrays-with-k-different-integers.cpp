class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k<=0) return 0;
        unordered_map<int,int> mp;
        int l=0,r=0;
        int cnt=0;
        int ans=0;
        while(r<nums.size()){
            if(mp.find(nums[r])==mp.end() || mp[nums[r]]==0){
                cnt++;
                mp[nums[r]]++;
            }
            else{
                mp[nums[r]]++;
            }
            if(cnt<=k){
                ans+=r-l+1;
                r++;
            }
            else{
                while(cnt > k){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) cnt--;
                    l++;
                }
                ans += r - l + 1;
                r++;
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};