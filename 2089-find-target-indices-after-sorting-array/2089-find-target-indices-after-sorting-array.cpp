class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());
       vector<int> ans;
        for(auto it = nums.begin(); it != nums.end(); it++){
            if(*it == target){
                ans.push_back(it - nums.begin());
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna