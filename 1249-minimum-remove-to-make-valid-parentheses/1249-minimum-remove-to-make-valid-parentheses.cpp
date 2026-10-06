class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<pair<char,int>> st; // char is string char and int is index.
        st.push({' ', -1}); // so st.top() will not give error at empty stack.
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
        while(st.size() > 1){ // wrong because st.size changes after popping, better to use st.empty() but becuase we have a sentinel have to use st.size() > 1 and a while loop.
            int remove = st.top().second;
            s.erase(remove, 1);
            st.pop();
        }
    return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna