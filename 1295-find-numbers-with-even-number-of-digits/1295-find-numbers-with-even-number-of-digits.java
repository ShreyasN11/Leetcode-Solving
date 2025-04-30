class Solution {
    int f(int x){
        int c = 0;
        while(x>0){
            x/=10; c++;
        }
        if(c%2 == 0) return 1; 
        else return 0; 
    }
    public int findNumbers(int[] nums) {
        int res = 0;
        for(int x: nums){
            res += f(x);
        }
        return res;
    }
}