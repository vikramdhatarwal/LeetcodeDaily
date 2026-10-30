class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1; // f(0, 0)

        for (int i = 1; i <= n; i++) {
            // iterate j downward so dp[j-1] is still the previous row's value
            for (int j = min(i, k); j >= 1; j--) {
                dp[j] = (dp[j - 1] + (long long)(i - 1) * dp[j]) % MOD;
            }
            dp[0] = 0; // f(i, 0) = 0 for i > 0
        }
        return (int)dp[k];
    }
};