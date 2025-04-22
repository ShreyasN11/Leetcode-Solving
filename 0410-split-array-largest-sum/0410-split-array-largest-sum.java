class Solution {
    boolean check(int mid, int [] nums, int k){
        int sum = 0;
        for(int x: nums){
            if(sum+x > mid){
                k--; 
                if(x>mid) return false;
                sum = x;
            }
            else sum+=x;
        }
        if(k<=0) return false;
        else return true;
    }
    public int splitArray(int[] nums, int k) {
        int sum = 0;
        for(int x: nums) sum +=x;
        int lo = 0; int hi = sum;
        int mini = Integer.MAX_VALUE;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,nums,k)){
                mini = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return mini;
    }
}