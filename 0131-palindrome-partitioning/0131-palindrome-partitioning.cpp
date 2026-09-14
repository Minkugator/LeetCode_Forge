class Solution {
public:
    bool palcheck(const string& test){ 
        string rev = test;
        reverse(rev.begin(), rev.end());
        return test == rev;
    }
    void subseqgen(const string& initial, vector<vector<string>>& ans, int rn, vector<string>& temp){
        if(rn == initial.length()){ 
            ans.push_back(temp);
            return; 
        }
        for(int j = rn; j < initial.length(); j++){
            string part = initial.substr(rn, j - rn + 1);
            if(palcheck(part)){
                temp.push_back(part);
                subseqgen(initial, ans, j + 1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
     vector<vector<string>> result;
     vector<string> change;
     subseqgen(s, result, 0, change);
     return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna