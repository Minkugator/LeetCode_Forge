class Solution {
public:
    bool canConstruct(string rn, string mag) {
        int freq[26]; // how to initialise this from 0.
        int n = mag.length();
        for(int i = 0; i < n; i++){
            freq[ mag[i] - 'a' ]++;
        }
        for(char c : rn){
            if(freq[ c - 'a' ] == 0 ){
                return false;
            }
            freq[ c - 'a' ]--;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna