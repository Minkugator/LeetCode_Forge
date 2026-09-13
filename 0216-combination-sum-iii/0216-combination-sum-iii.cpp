class Solution {
private:
    void subseqgen(const vector<int>& initial, vector<vector<int>>& ans,int k, int n, int sum,vector<int>& temp, int rn){
        if(temp.size() == k){
            if(sum == n){
                ans.push_back(temp);
                return;
            }
        }
        if(temp.size() > k) return;
        if(rn == initial.size()) return;
        if(sum > n) return;
        //take
        temp.push_back(initial[rn]);
        subseqgen(initial, ans, k, n , sum + initial[rn], temp, rn + 1);
        temp.pop_back();
        //omit   
        subseqgen(initial, ans, k, n , sum , temp, rn + 1);         
    }  
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int> initial;
      vector<vector<int>> result;
      for(int i = 1; i < 10; i++){
        initial.push_back(i);
      }
      vector<int> temp;
      subseqgen(initial, result, k, n, 0, temp, 0); 
      return result; 
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna