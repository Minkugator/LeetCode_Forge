class Solution {
private:
    long long MOD = 1e9 + 7;
    long long power(long long base, long long exp){
        long long ans = 1;
        base %= MOD;
        while(exp > 0){
            if(exp % 2 == 1){
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return ans;
    }

public:

    int countGoodNumbers(long long n) {
        long long even  = (n + 1) / 2;
        long long odd = n / 2;

        long long evenw = power(5,even);
        long long oddw = power(4,odd);

        return (evenw*oddw) % MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna