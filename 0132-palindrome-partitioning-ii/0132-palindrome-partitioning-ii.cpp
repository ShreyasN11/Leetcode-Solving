class Solution {
public:
    bool pal(string &s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int helper(int i, string &s, vector<int>&dp){
        if(i==s.length()) return 0;

        if(dp[i] != -1) return dp[i];

        int n = s.length();
        int mini = INT_MAX;

        for(int j=i; j<n; j++){
            if(pal(s,i,j)){
                mini = min(mini, 1+helper(j+1,s,dp));
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n,-1);
        return helper(0,s,dp) -1;
    }
};