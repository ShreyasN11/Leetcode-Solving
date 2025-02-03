class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1; int dec = 1; int maxi = 1;
        int i=1;
        while(i<n){
            if(i<n && nums[i-1] > nums[i]){
                inc++; dec =1;
            }
            else if(i<n && nums[i-1] < nums[i]){
                inc=1; dec++;
            }
            else{
                inc=1; dec=1;
            }
            maxi = max({maxi,dec,inc});
            i++;
        }
        return maxi;
    }
};