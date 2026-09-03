class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> f(26,0);
            for(int j = i; j < n; j++){
                f[s[j] - 'a']++;
                int mx = 0;
                int mn = 505;
                for(int k = 0; k < 26; k++){
                    if(f[k] > 0){
                    mx = max(mx,f[k]);
                    mn = min(mn,f[k]);
                }
            }
         ans += (mx - mn);
        }

    }
            return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna