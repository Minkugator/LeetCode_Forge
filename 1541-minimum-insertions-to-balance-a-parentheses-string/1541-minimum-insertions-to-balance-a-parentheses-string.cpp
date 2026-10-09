class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;
        for (char c : s) {
            if (c == '(') {
              if (need % 2 == 1) {
                    ans++;
                    need--;
                }
                need += 2;
            }
            else {
                need--;
                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }
        return ans + need;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna