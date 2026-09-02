class Solution {
private:
    int expand(const string& s, int left , int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int n = s.size();
        int mx = 0;
        int start = 0;  
        for(int i = 0 ; i < n; i++){
            int lenodd = expand(s,i,i);
            int leneven = expand(s,i,i+1);
            int winner = max(lenodd, leneven);
            if(mx < winner){
                mx = winner;
                start = i - (winner - 1) / 2;
            }
        }
        return s.substr(start, mx);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna