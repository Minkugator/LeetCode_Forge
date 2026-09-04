class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int mx = -1;
        int mn = INT_MAX;
        int ans = n;
        for(int i = 0; i < n; i++){
            if(nums[i] > mx){
                mx = nums[i];
            }
            for(int j = i; j < n; j++){
                if(nums[j] < mn){
                    mn = nums[j];
                }
            }
            if( (mx - mn) <= k){
                if(i < ans){
                    ans = i;
                }
            }
        mn = INT_MAX;
        }
        if(ans == n) return -1;
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna