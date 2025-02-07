class Solution {
public:
    bool check(string &s1, string &s2){
        if(s1.length()+1 != s2.length()) return false;
        int i=0; int j=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]== s2[j]){
                i++; j++;
            }
            else j++;
        }
        if(i==s1.length() && j==s2.length()) return true;
        if(i==s1.length() && j==s2.length()-1) return true;

        return false;
    }

    static bool cmp(string &s1, string &s2){
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        int n= words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(check(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};