class Solution {
    boolean helper(int i, int sum, int target, int[] nums, int [][] dp){
        if(i == 0){
            return sum == target;
        }
        if(dp[i][sum] != -1) return dp[i][sum] == 1;
        dp[i][sum] = (helper(i-1,sum+nums[i],target,nums,dp) || helper(i-1,sum,target,nums,dp)) ? 1 : 0;   
        return dp[i][sum] == 1;     
    }
    public boolean canPartition(int[] nums) {
        int sum = IntStream.of(nums).sum();
        if(sum%2 == 1) return false;
        int target = sum / 2;
        int n = nums.length;
        int[][] dp = new int[n+1][sum + 1];
        for(int i=0; i<n; i++){
            for(int j=0; j<=sum; j++){
                dp[i][j] = -1;
            }
        }

        return helper(n-1,0,target,nums,dp);
    }
}