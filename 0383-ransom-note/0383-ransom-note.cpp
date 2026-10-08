class Solution {
public:
    bool canConstruct(string rn, string mag) {
        unordered_map<char,int> ump;
        int n = mag.length();
        for(int i = 0; i < n; i++){
            ump[mag[i]]++;
        }
        int m = rn.length();
        for(int i = 0; i < m; i++){
            if( ump[rn[i]] == 0 ){
                return false;
            }
            else{
                ump[rn[i]]--;
            }
        }
        return true;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna