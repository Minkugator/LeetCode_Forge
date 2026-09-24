class Solution {
public:
    int sumdigit(int test){
        int temp = test;
        int ans = 0;
        while(temp > 0){
            int digit = temp % 10;
            ans = ans + digit;
            temp = temp / 10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i == sumdigit(nums[i])){
                return i;
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna