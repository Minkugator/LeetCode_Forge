class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        vector<vector<int>> presum(n, vector<int>(k + 1, 0));

        // Base: taken == k
        for (int i = n - 1; i >= 0; i--) {
            dp[i][k] = 1;

            if (i == n - 1) {
                presum[i][k] = 1;
            } else {
                presum[i][k] =
                    (dp[i][k] + presum[i + 1][k]) % MOD;
            }
        }

        // Fill remaining states
        for (int j = k - 1; j >= 0; j--) {
            for (int i = n - 1; i >= 0; i--) {

                // Can't make another segment
                if (i == n - 1) {
                    dp[i][j] = 0;
                    presum[i][j] = 0;
                    continue;
                }

                dp[i][j] =
                    (dp[i + 1][j] + presum[i + 1][j + 1]) % MOD;

                presum[i][j] =
                    (dp[i][j] + presum[i + 1][j]) % MOD;
            }
        }

        return dp[0][0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna