class Solution {
public:
    vector<int> dp;
    vector<vector<bool>> ispal;
    int solve(int index, const string& s, int k){
        if(index == s.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int best = solve(index + 1, s,k);
        for(int end = index + k -1; end < s.size(); end++){
            if(ispal[index][end]){
                best = max(best, 1 + solve(end + 1, s, k) );
                }
            }
        
        dp[index] = best;
        return best;
     }
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        dp.assign(n , -1);
        ispal.assign(n, vector<bool>(n, false));
        for(int i = n; i >= 0; i--){
            for(int j = i; j < n; j++){
                if((s[i] == s[j]) && (j - i <= 1 || ispal[i + 1][j - 1])){
                    ispal[i][j] = true;
                }
            }
        }
        return solve(0,s,k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna