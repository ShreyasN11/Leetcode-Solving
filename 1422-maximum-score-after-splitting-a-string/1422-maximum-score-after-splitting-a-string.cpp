class Solution {
public:
    int maxScore(string s) {
        int maxi = 0;
        int ones = 0;
        int zeros = 0;
        for(auto it: s){
            if(it=='1') ones++;
        }
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '0') zeros++;
            else ones--;
            maxi = max(maxi,zeros+ones);
        }
        return maxi;
    }
};