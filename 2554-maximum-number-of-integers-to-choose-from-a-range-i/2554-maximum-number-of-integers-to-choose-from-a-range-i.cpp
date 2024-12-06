class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st(banned.begin(),banned.end());
        int count = 0; int cur = 1;
        while(cur<=n){
            if(st.find(cur) == st.end()){
                if(maxSum - cur <0) return count;
                count++; maxSum -= cur;
            }
            cur++;
        }
        return count;
        
    }
};