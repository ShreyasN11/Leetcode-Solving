class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }
        int lo=0; int hi=1;
        int count = 0;
        while(lo<n && hi<n+k){
            if(colors[hi] == colors[hi-1]){
                lo=hi;
                hi++; continue;
            }
            else if(hi-lo == k-1){
                count++;
                lo++;
            }
            hi++;
        }

        return count;

    }
};