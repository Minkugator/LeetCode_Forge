/*class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<pair<char,int>> st; // char is string char and int is index.
        st.push({' ', -1}); // so st.top() will not give error at empty stack.
        vector<bool> ass(n, true);
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push({s[i], i}); // remembering that use {} to push pairs.
            }
            else if(s[i] == ')' ){
                char prev = st.top().first; // mercy if I butchered the syntax
                if(prev == '('){ // no need for second condition as already checked that
                    st.pop();
                }
                else{
                    st.push({s[i], i});
                }
            }
        }
        while(st.size() > 1){
            ass[st.top().second] = false;
            st.pop();
        }
        string ans;
        for(int i = 0; i < n; i++){
            if(ass[i]){
                ans += s[i];
            }
        }
    return ans;
    }
};
*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.length();

        stack<int> st;
        vector<bool> keep(n, true);

        for(int i = 0; i < n; i++) {

            if(s[i] == '(') {
                st.push(i);
            }

            else if(s[i] == ')') {

                if(!st.empty()) {
                    st.pop();
                }
                else {
                    keep[i] = false;
                }
            }
        }

        while(!st.empty()) {
            keep[st.top()] = false;
            st.pop();
        }

        string ans;

        for(int i = 0; i < n; i++) {
            if(keep[i]) {
                ans += s[i];
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna