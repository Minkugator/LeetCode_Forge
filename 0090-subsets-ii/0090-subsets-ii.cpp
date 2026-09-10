class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, int index, vector<int>& current) {
        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            
            // Skip duplicate choices at the same recursion level
            if (i > index && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);
            solve(nums, i + 1, current);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        solve(nums, 0, current);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna