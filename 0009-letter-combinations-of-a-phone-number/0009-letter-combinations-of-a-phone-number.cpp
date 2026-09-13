class Solution {
private:
    void substringgen(const string& initial, vector<string>& result, int rn, string& temp, unordered_map<int, string>& ump){
        if(rn == initial.length()){
            result.push_back(temp);
            return;
        }
        int digit = initial[rn] - '0';
        for(auto it : ump[digit]){
            temp.push_back(it);
            substringgen(initial, result, rn+1, temp, ump);
            temp.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<int, string> mp;
        char ch = 'a';
        for(int curr = 2; curr <= 9; curr++){
            int count = (curr == 7 || curr == 9 ) ? 4 : 3;
            for(int j = 0; j < count; j++){
                mp[curr] += ch;
                ch++;
            }
        }
        vector<string> result;
        string temp;
        substringgen(digits, result, 0, temp, mp);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna