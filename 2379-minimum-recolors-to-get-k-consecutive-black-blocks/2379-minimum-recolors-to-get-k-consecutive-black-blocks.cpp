class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<k; i++){
            if(s[i] == 'B') count++;
        }
        int mini = k-count;
        int hi = k; int lo = 0;
        while(hi<n){
            if(s[lo] == 'B') count--;
            if(s[hi] == 'B') count++;
            mini = min(mini, k-count);
            lo++; hi++;
        }
        return mini;
    }
};