class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int lo = 0; int hi=0;
        int bitmask = 0;
        int maxi = 0;
        while(hi<n){
            while(hi<n && (nums[hi] ^ bitmask) == (nums[hi] | bitmask)){
                bitmask = bitmask ^ nums[hi];
                hi++;
            }
            maxi = max(maxi,hi-lo);
            lo=hi;
            bitmask = 0;
        }
        return maxi;
    }
};

/*





*/