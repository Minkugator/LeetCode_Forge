class Solution {
private:
    void specific(int n, int lf, int rf, string s,vector<string>& ans){
        if(s.length() == 2*n){
            ans.push_back(s);
            return;
        }
        if(rf < n){
            specific(n,lf,rf+1,s+'(',ans);
        }
        if(rf - lf > 0){
            specific(n,lf+1,rf,s+')',ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        specific(n,0,0,"",result);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna