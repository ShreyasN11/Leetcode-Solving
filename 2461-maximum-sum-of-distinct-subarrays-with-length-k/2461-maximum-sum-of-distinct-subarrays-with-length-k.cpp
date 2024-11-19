class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0; int j=0;
        set<long long>st;
        long long sum = 0;
        long long maxi = 0;
        while(i<n && j<n){
            if( j-i < k && st.find(nums[j]) == st.end()){
                sum += nums[j];
                st.insert(nums[j]);
                j++;                
                if(j-i == k){
                    maxi = max(maxi,sum);
                }
            }
            else{
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
        }
        return maxi;
    }
};