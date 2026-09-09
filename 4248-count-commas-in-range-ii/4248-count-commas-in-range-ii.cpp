class Solution {
public:
    long long countCommas(long long n) {
        long long comma = 0;
        if(n < 1000) return 0;
        long long start = 1000;
        int power = 3;
        int commas = 1;
        while (start <= n){
            long long end = pow(10, power + 3) - 1;
            long long numbers = min(n,end) - start + 1;

            comma += numbers*commas;

            start = pow(10, power + 3);
            commas++;
            power = power + 3;
        }

        return comma;   
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna