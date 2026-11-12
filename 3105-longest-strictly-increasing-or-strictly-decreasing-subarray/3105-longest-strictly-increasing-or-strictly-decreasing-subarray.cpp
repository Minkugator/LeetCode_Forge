class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incmax = 1;
        int decmax = 1;
        int n =  nums.size();
        int inc = 1;
        int dec = 1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i+1]){
                dec++;
                decmax = max(dec, decmax);
                inc = 1;
            }
            else if(nums[i] < nums[i + 1]){
                inc++;
                incmax = max(incmax, inc);
                dec = 1;
            }
            else{
                inc = 1;
                dec = 1;
            }
        }
        return max(incmax, decmax);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna