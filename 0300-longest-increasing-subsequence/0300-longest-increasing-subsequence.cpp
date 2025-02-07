class Solution {
public:
    int helper(int index,int prev, vector<vector<int>> &dp, vector<int> &nums){
        if(index>=nums.size()) return 0;
        if(dp[index][prev+1] != -1) return dp[index][prev+1];
        int notake = 0 + helper(index+1,prev,dp,nums);
        int take = 0;
        if(prev == -1 || nums[prev] < nums[index]){
            take = 1+helper(index+1,index,dp,nums);
        }
        return dp[index][prev+1] = max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,-1,dp,nums);
    }
};