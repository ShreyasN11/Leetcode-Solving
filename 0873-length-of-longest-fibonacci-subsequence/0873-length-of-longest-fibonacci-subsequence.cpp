class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int>st(arr.begin(),arr.end());
        int n = arr.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int curlen = 2;
                int prevprev = arr[i];
                int prev = arr[j];
                int cur = prev + prevprev;
                while(st.find(cur) != st.end()){
                    prevprev = prev;
                    prev = cur;
                    cur = prevprev+prev;
                    curlen++;
                    maxi = max(maxi,curlen);
                }
            }
            st.erase(arr[i]);
        }
        return maxi;
    }
};