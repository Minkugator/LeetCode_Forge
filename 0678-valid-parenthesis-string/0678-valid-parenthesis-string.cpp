class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }

            else if (c == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;   // '*' acts as ')'
                high++;  // '*' acts as '('
            }

            // We cannot have negative possible opening brackets
            low = max(0, low);

            // Even our best case has too many ')'
            if (high < 0)
                return false;
        }

        // There must be some interpretation with exactly 0 opens
        return low == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna