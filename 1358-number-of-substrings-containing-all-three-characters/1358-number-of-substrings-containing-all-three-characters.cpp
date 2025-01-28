class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int>count(3,0);
        int lo=0; int hi=0;
        int sum = 0;
        while(hi<n){
            while(hi<n && count[0] == 0 || count[1] == 0 || count[2] == 0){
                char ch = s[hi];
                count[ch - 'a']++;
                hi++;
            }
            while(lo<hi && count[0] > 0 && count[1] > 0 && count[2] > 0){
                sum += n-hi+1;
                char ch = s[lo];
                count[ch - 'a']--;
                lo++;
            }
        }
        return sum;
    }
};