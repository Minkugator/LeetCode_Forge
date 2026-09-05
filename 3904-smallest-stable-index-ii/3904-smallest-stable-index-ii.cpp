class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Build suffix minimum array where suffix_min[i] = min(nums[i..n-1])
        std::vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = std::min(nums[i], suffix_min[i + 1]);
        }
        
        int prefix_max = nums[0];
        
        // Iterate left-to-right to evaluate the instability score
        for (int i = 0; i < n; ++i) {
            prefix_max = std::max(prefix_max, nums[i]);
            long long instability_score = (long long)prefix_max - suffix_min[i];
            
            if (instability_score <= k) {
                return i;
            }
        }
        
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna