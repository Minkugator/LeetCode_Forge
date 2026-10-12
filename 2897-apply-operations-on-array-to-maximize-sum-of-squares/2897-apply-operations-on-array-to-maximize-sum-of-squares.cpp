class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int cnt[31] = {0};

        for (int num : nums) {
            for (int i = 0; i < 31; i++) {
                if ((num >> i) & 1) {
                    cnt[i]++;
                }
            }
        }

        long long ans = 0;

        while (k--) {
            int x = 0;

            for (int i = 0; i < 31; i++) {
                if (cnt[i] > 0) {
                    x |= (1 << i);
                    cnt[i]--;
                }
            }

            ans = (ans + 1LL * x * x) % MOD;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna