class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n,INT_MAX);
        mini[0] =0;
        for(int i=0; i<n; i++){
            int x = nums[i];
            int w = mini[i]+1;
            for(int j=i+1; j<=i+x && j<n; j++){
                mini[j] = min(w,mini[j]);
            }
        }
        return mini[n-1];
    }
};