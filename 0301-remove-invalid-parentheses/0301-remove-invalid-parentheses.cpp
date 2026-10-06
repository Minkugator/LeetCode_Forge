class Solution {
public:
    set<string> ans;
    void solve(int i, const string& s, string& curr, int closerem, int openrem, int bal){
        if(i == s.length()){
            if(closerem == 0 && openrem == 0 && bal == 0){
                ans.insert(curr);
            }
            return;
        }
        if(s[i] == ')'){
            if(closerem > 0){
                solve(i + 1, s, curr, closerem - 1, openrem, bal);
            }
            if(bal > 0){
            curr.push_back(')');
            solve(i + 1, s, curr, closerem, openrem, bal - 1);
            curr.pop_back();
            }
        }
        else if(s[i] == '('){
            if(openrem > 0){
                solve(i + 1, s, curr, closerem, openrem - 1, bal);
            }
            curr.push_back('(');
            solve(i + 1, s, curr, closerem, openrem, bal + 1);
            curr.pop_back();
        }
        else{
            curr.push_back(s[i]);
            solve(i + 1, s, curr, closerem, openrem, bal);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        int balance = 0;
        int cr = 0;
        int openr = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') balance++;
            else if(s[i] == ')'){
                if(balance > 0){
                    balance--;
                }
                else{
                    cr++;
                }
            }
        }
        openr = balance;
        string temp = "";
        solve(0, s, temp, cr, openr, 0);
        vector<string> trueans;
        for(auto it : ans){
            trueans.push_back(it);
        }
        return trueans; // have no clue what to do for empty strings, using 0 insted of bal counters that
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna