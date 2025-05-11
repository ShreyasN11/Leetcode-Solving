class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0; int j=0;
        int n = arr.size();
        while(j<n){
            while(j<n && arr[j++]%2 == 1){
                if(j-i >= 3) return true;
            }
            i=j;
        }
        return false;
    }
};