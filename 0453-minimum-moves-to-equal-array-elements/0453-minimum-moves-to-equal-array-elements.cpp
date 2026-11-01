class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int mn = *min_element(nums.begin(), nums.end());
        for (int x : nums) sum += x;
        return (int)(sum - (long long)mn * nums.size());
    }
};