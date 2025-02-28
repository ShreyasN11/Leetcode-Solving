class Solution {
public:
    int helper(string &s, string &t, vector<vector<int>> &dp, int i, int j){
        if(i<=0 || j<=0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]){
            return dp[i][j] = 1+helper(s,t,dp,i-1,j-1);
        }
        else return dp[i][j] = max(helper(s,t,dp,i-1,j),helper(s,t,dp,i,j-1));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(); int m=str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        helper(str1,str2,dp,n,m);
        string res="";
        int i=n; int j=m;
        while(j>0 && i>0){
            if(str1[i-1] == str2[j-1]){
                i--; j--; res+=str1[i];
            }
            else if(dp[i][j-1] > dp[i-1][j]){
                j--; res+=str2[j];
            }
            else{
                i--; res+=str1[i];
            }
        }
        while(i>0){
            res+=str1[i-1]; i--;
        }
        while(j>0){
            res+=str2[j-1]; j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};