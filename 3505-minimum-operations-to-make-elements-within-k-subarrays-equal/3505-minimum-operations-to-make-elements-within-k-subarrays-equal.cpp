#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m;
    vector<int> cntB;
    vector<long long> sumB;
    vector<long long> vals;

    void update(int i, int c, long long v) {
        for (; i <= m; i += i & -i) { cntB[i] += c; sumB[i] += v; }
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // coordinate compression
        vals.assign(nums.begin(), nums.end());
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        m = vals.size();
        cntB.assign(m + 1, 0);
        sumB.assign(m + 1, 0);

        auto idx = [&](int v) {
            return int(lower_bound(vals.begin(), vals.end(), (long long)v) - vals.begin()) + 1;
        };

        int LOG = 1;
        while ((1 << LOG) <= m) LOG++;

        // cost[s] = cost of making window [s, s+x-1] equal
        vector<long long> cost(n - x + 1);
        long long S = 0;
        for (int i = 0; i < n; i++) {
            update(idx(nums[i]), 1, nums[i]);
            S += nums[i];
            if (i >= x) {
                update(idx(nums[i - x]), -1, -nums[i - x]);
                S -= nums[i - x];
            }
            if (i >= x - 1) {
                // find median (kth smallest, 1-indexed)
                int kth = (x + 1) / 2, pos = 0;
                for (int b = LOG; b >= 0; b--) {
                    int np = pos + (1 << b);
                    if (np <= m && cntB[np] < kth) {
                        pos = np;
                        kth -= cntB[np];
                    }
                }
                long long med = vals[pos];          // index pos+1 in 1-based BIT
                // prefix count/sum of elements <= median
                long long cl = 0, sl = 0;
                for (int p = pos + 1; p > 0; p -= p & -p) { cl += cntB[p]; sl += sumB[p]; }
                cost[i - x + 1] = med * cl - sl + (S - sl) - med * (x - cl);
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (i >= x && dp[j - 1][i - x] < INF)
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
            }
        }
        return dp[k][n];
    }
};