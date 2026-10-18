class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        // Pascal's triangle mod p: comb[i][j] = C(i, j)
        vector<vector<long long>> comb(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        function<long long(const vector<int>&)> count = [&](const vector<int>& arr) -> long long {
            if (arr.size() <= 2) return 1;

            vector<int> left, right;
            for (size_t i = 1; i < arr.size(); i++) {
                if (arr[i] < arr[0]) left.push_back(arr[i]);
                else right.push_back(arr[i]);
            }

            long long ways = comb[arr.size() - 1][left.size()];
            return ways * count(left) % MOD * count(right) % MOD;
        };

        return (count(nums) - 1 + MOD) % MOD;
    }
};