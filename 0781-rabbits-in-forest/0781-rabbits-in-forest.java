class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> mp = new HashMap<>();
        int res = 0;
        for(int x : answers) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        for(Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int x = entry.getKey(); int freq = entry.getValue();
            res += ((freq+x)/(x+1)) * (x+1);
            // System.out.println(res);
        }
        return res;
    }
}