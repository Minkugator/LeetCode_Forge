class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, vector<int>> mp;
        int n = s.length();
        for(int i = 0; i < n; i++){
            mp[s[i]].push_back(i);
        }
        vector<bool> seen(26 , false);
        vector<vector<int>> interval(26, vector<int>(2,-1));
        for(int j = 0; j < n; j++){
            int inx = s[j] - 'a';
            if(seen[inx] == false){
                seen[inx] = true;
                int first = mp[s[j]].front();
                int last = mp[s[j]].back();
                interval[inx] = {first, last};
            }
            else{
                continue;
            }            
        }
        vector<pair<int,int>> validint;
        for(int x = 0; x < 26; x++){
            if(!seen[x]) continue;
            int l = interval[x][0];
            int r = interval[x][1];
            bool valid = true;
            for(int i = l; i <= r; i++){
                int curr = s[i] - 'a';
                if(interval[curr][0] < l){
                    valid = false;
                    break;
                }
                if(interval[curr][1] > r){
                    r = interval[curr][1];
                }
            }
            if(valid){
                validint.push_back({l,r});
            }
       }
       vector<pair<int,int>> ans;
        int prevend = -1;
        sort(validint.begin(), validint.end(),[](auto &a, auto &b){
            return a.second < b.second;
                });
        for(auto &in : validint){
            if(in.first > prevend){
                prevend = in.second;
                ans.push_back(in);
            }
        }
        vector<string> result;
        for(auto &it : ans){
            result.push_back(s.substr(it.first, it.second - it.first + 1));
        }
        return result;
    } 
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna