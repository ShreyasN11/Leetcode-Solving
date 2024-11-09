class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>res(n);
        int x = 0;
        int maxi = pow(2,maximumBit)-1;
        for(int i=0; i<n; i++){
            x ^= nums[i];
            res[n-i-1] = x^maxi;
        }
        return res;
    }
};

/*

10 -> 01
2^3 = 111-11 = 100;


*/