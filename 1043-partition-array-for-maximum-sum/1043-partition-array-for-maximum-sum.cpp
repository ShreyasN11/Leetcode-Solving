class Solution {
public:
    int helper(int index, vector<int> &arr, int k, vector<int> &dp){
        int n = arr.size();
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        int len = 0; int maxi = arr[index]; int maxsum = 0;
        for(int i=index; i< min(index+k,n); i++){
            len++;
            maxi=max(maxi,arr[i]);
            int cursum = len*maxi + helper(i+1,arr,k,dp);
            maxsum = max(maxsum,cursum);
        } 
        return dp[index] = maxsum;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return helper(0,arr,k,dp);
    }
};