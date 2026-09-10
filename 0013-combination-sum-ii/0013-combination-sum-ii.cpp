class Solution {
private:
void subseqgen(const vector<int>& initial, vector<int>& temp, vector<vector<int>>& result, int start, int total, int sum){
        if(sum == total){
        result.push_back(temp);
        return;
    }
    if(sum > total) return; 
    if(start == initial.size()) return;

        for(int i = start; i < initial.size(); i++){
            if(i > start && initial[i] == initial[ i - 1]){
                continue;
                }
            temp. push_back(initial[i]);
            subseqgen(initial, temp, result, i + 1, total, sum + initial[i]);
            temp.pop_back();
        
        }    
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> change;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>answer;                                                          subseqgen(candidates, change, answer, 0, target, 0);
        return answer;           
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna