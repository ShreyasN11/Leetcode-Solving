class Solution {
    public int longestSubsequence(int[] arr, int d) {
        Map<Integer, Integer> map = new HashMap<>();
        int maxi = 1;
        for(int x: arr){
            if(map.containsKey(x-d)){
                int n = map.get(x-d)+1;
                map.put(x, n);
                maxi = Math.max(maxi,n);
            }
            else map.put(x,1);
        }
        return maxi;
    }
}