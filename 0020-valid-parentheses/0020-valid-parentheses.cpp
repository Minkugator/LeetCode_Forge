class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char first = st.top();
                st.pop();
                if ((c == ')' && first != '(') ||
                    (c == ']' && first != '[') ||
                    (c == '}' && first != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna