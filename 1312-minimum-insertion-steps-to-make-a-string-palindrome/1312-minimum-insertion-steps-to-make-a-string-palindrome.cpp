class Solution {
public:
    int helper(string &s, int lo, int hi, vector<vector<int>> &dp){
        if(lo>=hi) return 0;
        if(dp[lo][hi] != -1) return dp[lo][hi];
        if(s[lo] == s[hi]) return dp[lo][hi] = helper(s,lo+1,hi-1,dp);
        else return dp[lo][hi] = 1+ min(helper(s,lo+1,hi,dp),helper(s,lo,hi-1,dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return helper(s,0,s.size()-1, dp);
    }
};