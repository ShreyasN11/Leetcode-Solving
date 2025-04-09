class Solution {
    public int shortestSequence(int[] rolls, int k) {
        boolean[] check = new boolean[k+1];
        int count = 0; int total = 0;
        int n = rolls.length;
        for(int i=0; i<n; i++){
            if(!check[rolls[i]]){
                check[rolls[i]] = true;
                count++;
            }
            if(count == k){
                Arrays.fill(check,false);
                total++;
                count=0;
            }
        }
        return total+1; 
    }
}