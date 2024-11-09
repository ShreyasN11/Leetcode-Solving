class Solution {
public:
    int largestCombination(vector<int>& arr) {
        int n = arr.size();
        vector<int>bitmap(32,0);
        for(int i=0; i<n; i++){
            int x = arr[i];
            int bit = 0;
            while(x){
                if(x%2==1){
                    bitmap[bit]++;
                }
                x/=2; bit++;
            }
        }

        return *max_element(bitmap.begin(), bitmap.end());
    }
};