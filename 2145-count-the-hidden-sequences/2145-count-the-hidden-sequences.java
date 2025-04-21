class Solution {
    int check(int x, int[] d, int lower, int upper){
        for(int i=0; i<d.length; i++){
            x += d[i];
            if(x>=lower && x<=upper) continue;
            else if(x>upper) return 1;
            else return -1;
        }
        return 0;
    }
    public int numberOfArrays(int[] d, int lower, int upper) {
        int n = d.length;
        int lo = lower; int hi = upper; int mini = Integer.MAX_VALUE; int maxi = Integer.MIN_VALUE;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int c = check(mid,d,lower,upper);
            if(c == 0){
                hi = mid-1;
                mini = mid;
            }
            else if(c == -1){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        lo = lower; hi = upper;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int c = check(mid,d,lower,upper);
            if(c == 0){
                lo = mid+1;
                maxi = mid;
            }
            else if(c==1){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        if(maxi < mini) return 0;

        return maxi - mini + 1;
    }
}