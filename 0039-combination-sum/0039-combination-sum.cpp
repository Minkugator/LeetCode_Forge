class Solution {
private:
    void subseqgen(const vector<int>& initial, vector<int>& temp, vector<vector<int>>& result, int rn ,int total, int curr){
        if(rn == initial.size()) return;
        if(curr > total) return;
        if(curr == total){
            result.emplace_back(temp);
            return;
        }
        else{
            // take
            temp.push_back(initial[rn]);
            subseqgen(initial, temp, result, rn, total, curr + initial[rn]);
            temp.pop_back();
            // omit
            subseqgen(initial, temp, result, rn + 1, total, curr);
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> change;
        vector<vector<int>> answer;
        subseqgen(candidates, change, answer, 0, target, 0);
        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna