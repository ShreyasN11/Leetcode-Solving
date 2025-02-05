class Solution {
public:
    bool helper(int i, int count, string &s, vector<vector<int>>&dp){
        if(count<0) return false;
        if(i== s.length()){
            return count == 0;
        }
        if(dp[i][count] != -1) return dp[i][count];
        if(s[i] == '(') return dp[i][count] = helper(i+1, count+1, s, dp);
        if(s[i] == ')') return dp[i][count] = helper(i+1, count-1, s, dp);
        bool temp = helper(i+1, count-1, s, dp) || helper(i+1, count+1, s, dp) || helper(i+1, count, s, dp);
        return dp[i][count] = temp;
    }
    bool checkValidString(string s) {
        int n= s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(0,0,s ,dp);
    }
};