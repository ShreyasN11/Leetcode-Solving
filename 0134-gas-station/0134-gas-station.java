class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int sum1 = 0; int sum2 = 0;
        for(int i=0; i<gas.length; i++){
            sum1 += gas[i];
            sum2 += cost[i];
        }
        if(sum1 < sum2) return -1;

        int cur = 0;
        int i=0; int idx = 0;
        while(i<gas.length){
            cur += gas[i] - cost[i];
            if(cur<0){
                cur = 0;
                idx = i+1;
            }
            i++;
        }
        return idx;
    }
}