class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int n = nums.size();
       int low = 0;
       int high = n - 1;
        while( high > 0 && nums[high] == val){
            high--;
        }
        for(low; low <= high; low++){
            if(nums[low] == val){
                    while( high > 0 && nums[high] == val){
                            high--;
                            }
            if(high < low){
                break;
            }
            swap(nums[low], nums[high]);
            high--;
            }
        }
        return high + 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna