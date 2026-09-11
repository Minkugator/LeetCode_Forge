class Solution {
private:
    void subseqgen(const vector<int>& initial, vector<int>& temp, set<vector<int>>& st, vector<bool>& used){
        if(temp.size() == 3){
            if(temp[2]%2 == 0){
                st.insert(temp);
            }
            return;
        }
        for(int i = 0; i < initial.size(); i++){
            if(used[i]) continue;
            if(temp.empty() && initial[i] == 0) continue;

            used[i] = true;
            temp.push_back(initial[i]);
            subseqgen(initial, temp, st, used);
            temp.pop_back();
            used[i] = false;
        }
    }
public:
    int totalNumbers(vector<int>& digits) {
        set <vector<int>> mp;
        vector<int> change;
        vector<bool> all(digits.size(), false);
        subseqgen(digits, change, mp , all);
        return mp.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna