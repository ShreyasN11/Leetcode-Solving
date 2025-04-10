class Solution {
    int helper(int i, int j, String word1, String word2,int[][]dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1.charAt(i) == word2.charAt(j)){
            dp[i][j] = helper(i-1,j-1,word1,word2,dp);
        }
        else{
            dp[i][j] = 1 + Math.min(helper(i-1,j,word1,word2,dp), Math.min(helper(i,j-1,word1,word2,dp), helper(i-1,j-1,word1,word2,dp)));
        }
        return dp[i][j];
    }
    public int minDistance(String word1, String word2) {
        int n =word1.length();
        int m = word2.length();
        int[][] dp = new int[n+1][m+1];
        for (int[] row : dp) Arrays.fill(row, -1);
        return helper(n-1,m-1,word1,word2,dp);
    }
}