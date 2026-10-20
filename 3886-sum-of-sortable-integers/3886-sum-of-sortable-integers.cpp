class Solution {
public:
    // block is [i, j)
    bool is_sortable(vector<int>& nums, int i, int j){
        int peak = 0;
        for(int x = i; x < j; x++){
            int nxt = (x + 1 < j) ? nums[x + 1] : nums[i];
            if(nums[x] > nxt) peak++;
        }
        return peak <= 1;
    }

    bool check(vector<int>& nums, int k){
        int n = nums.size();
        int prevMax = 0;                                     

        for(int j = 0; j < n; j += k){
            if(!is_sortable(nums, j, j + k)) return false;

            int mn = INT_MAX, mx = INT_MIN;                  
            for(int x = j; x < j + k; x++){
                mn = min(mn, nums[x]);
                mx = max(mx, nums[x]);
            }
            if(mn < prevMax) return false;                
            prevMax = mx;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                if(check(nums, i)) ans += i;
                if(i != n / i && check(nums, n / i)) ans += n / i;
            }
        }
        return ans;
    }
};