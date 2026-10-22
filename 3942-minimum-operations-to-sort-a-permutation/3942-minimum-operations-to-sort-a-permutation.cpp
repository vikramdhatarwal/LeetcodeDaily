class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int p = -1;
        for(int i=0; i<n; ++i) {
            if(!nums[i]) {
                p = i;
                break;
            }
        }
        
        bool ok1 = 1, ok2 = 1;
        for(int i=0; i<n; ++i) {
            if(nums[(p + i) % n] != i) ok1 = 0;
            if(nums[(p + i) % n] != (n - i) % n) ok2 = 0;
        }
        
        if(ok1) {
            if(p == 0) return 0;
            return min(p, n - p + 2);
        }
        
        if(ok2) {
            return min(p + 2, n - p);
        }
        
        return -1;
    }
};