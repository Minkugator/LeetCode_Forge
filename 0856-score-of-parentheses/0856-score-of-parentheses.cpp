class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // to make sure the top function after empty stack is valid.
        for(char c : s){
            if(c == '('){
                st.push(0);
            }
            else{
                int value = st.top(); // what is the score at current level
                st.pop();
                int curr; // to make sure score goes to the level above 
                if(value == 0){
                    curr = 1;
                }
                else{
                    curr = 2*value;
                }
                st.top() += curr;
            }
        }
        return st.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna