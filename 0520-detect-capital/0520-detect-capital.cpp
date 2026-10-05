class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 1) return true;
        int n = word.length();
        int caps = 0;
        for(char c : word){
            if(c >= 'A' && c <= 'Z'){
                caps++;
            }
        }
        if(caps == 0 || caps == n){
            return true;
        }
        else if(caps == 1){
            if(word[0] >= 'A' && word[0] <= 'Z') return true;
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna