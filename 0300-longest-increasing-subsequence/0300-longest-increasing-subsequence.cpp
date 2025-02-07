class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};