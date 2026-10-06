class Solution {
public:
    int minAddToMakeValid(string s) {
     int n = s.length();
     stack<char> st;
     st.push(' ');
     for(int i = 0; i < n; i++){
        char prev = st.top();
        if(prev == '(' && s[i] == ')'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
     }
     return st.size() - 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna