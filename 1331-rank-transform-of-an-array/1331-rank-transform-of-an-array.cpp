class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};
        vector<tuple<int, int ,int>> finder; //  value, rank, og index
        for(int i = 0; i < n; i++){
            finder.push_back({arr[i], 0, i});
        }
        sort(finder.begin(), finder.end());
        get<1>(finder[0]) = 1;
        int rank = 1;
        for(int i = 1; i < n; i++){
            if(get<0>(finder[i]) != get<0>(finder[i - 1])){
                rank++;
            }
            get<1>(finder[i]) = rank;
        }
        sort(finder.begin(), finder.end(), [](const auto& x, const auto& y){
            return get<2>(x) < get<2>(y);
        });
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(get<1>(finder[i]));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna