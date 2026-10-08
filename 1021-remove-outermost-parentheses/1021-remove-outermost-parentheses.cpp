class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int balance = 0;
        for(char c : s){
            if(c == '('){
                if(balance > 0) ans += c;
                balance++;
            }
            else{
                balance--;
                if(balance > 0) ans += c;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna