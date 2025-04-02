class Solution {
    public long maximumTripletValue(int[] nums) {
        long maxi = 0;
        int n = nums.length;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    maxi = Math.max(maxi, (long) (nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return maxi;
    }
}