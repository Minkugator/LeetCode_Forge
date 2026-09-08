class Solution {
public:
    int countCommas(int n) {
        int comma = 0;
        if(n < 1000) return 0;
        else{
            comma = n - 1000 + 1;;
        }
        return comma;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna