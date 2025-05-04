class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<String, Integer> map = new HashMap<>();
        int res = 0;
        for(int[]x : dominoes){
            int a = x[0]; int b = x[1];
            int a1 = Math.min(a,b); int b1 = Math.max(a,b);
            String key = a1 + ":" + b1;
            res += map.getOrDefault(key,0);
            map.put(key,(map.getOrDefault(key,0) + 1));
        }
        return res;
    }
}