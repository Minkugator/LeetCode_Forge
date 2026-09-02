class Solution {
private:
    int getval(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else if(c == 'M') return 1000;
        return 0;
    }
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        if(n == 1) return getval(s[0]);
        for(int i = 0; i < n - 1; i++){
            if(getval(s[i]) < getval(s[i + 1]) ){
                ans = ans + (getval(s[i + 1]) - getval(s[i]) );
                i++;
            }
            else{
                ans = ans + getval(s[i]);
            }
        }
        if(n >= 2){
        if(getval(s[n - 2]) < getval(s[n-1])) return ans;
        else{
            ans += getval(s[n-1]);
        }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna