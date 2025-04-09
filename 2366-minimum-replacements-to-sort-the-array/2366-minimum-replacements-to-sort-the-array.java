class Solution {
    public long minimumReplacement(int[] nums) {
        int n = nums.length;
        int prev = nums[n-1];
        long count = 0;
        for(int i=n-2; i>=0; i--){
            if(nums[i] > prev){
                int sec = (nums[i]+prev-1)/prev;
                // System.out.println(sec);
                int rem = nums[i]%sec;
                prev = nums[i]/sec;
                count += sec-1;
                // System.out.println(sec);
            }
            else prev = nums[i];
        }
        return count;
    }
}