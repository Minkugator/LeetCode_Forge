class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            string temp = words[i];
            bool pushed = false;
            for(int j = 0; j < temp.length(); j++){                
                if(temp[j] == x && pushed != true){
                    ans.push_back(i);
                    pushed = true;
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna