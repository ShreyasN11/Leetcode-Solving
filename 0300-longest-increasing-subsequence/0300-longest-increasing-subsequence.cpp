class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index =n-1; index>=0; index--){
            for(int prev=index-1; prev>=-1; prev--){
                int notake = dp[index+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[prev] < nums[index]){
                    take = 1+dp[index+1][index+1];
                }
                dp[index][prev+1] = max(take,notake);
            }
        }
        return dp[0][0];
    }
};