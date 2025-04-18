class Solution {
    String helper(int n){
        if(n==0) return "1";
        String cur = helper(n-1);
        String rle = "";
        int m = cur.length();
        int start = m-1; int i = m-1;
        while(i>=0){
            while(i>=0 && cur.charAt(i) == cur.charAt(start)){
                i--;
            }
            int len = start-i;
            rle = String.valueOf(len) + cur.charAt(start) + rle;
            start = i;
        }
        return rle;        
    }
    public String countAndSay(int n) {
        return helper(n-1);
    }
}