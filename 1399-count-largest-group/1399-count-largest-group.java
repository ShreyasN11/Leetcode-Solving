class Solution {
    int f(int x){
        int sum = 0;
        while(x>0){
            sum += x%10;
            x/=10;
        }
        return sum;
    }
    public int countLargestGroup(int n) {
        Map<Integer,Integer>mp = new HashMap<>();
        int maxi = 1;
        for(int i=1; i<=n; i++){
            int sum = f(i);
            if(mp.containsKey(sum)){
                int y = mp.get(sum) +1;
                mp.put(sum,y);
                maxi = Math.max(maxi,y);
            }
            else{
                mp.put(sum,1);
            }
        }
        int ans = 0;
        for (var it : mp.entrySet()) {
            if (it.getValue().equals(maxi)) {
                ans++;
            }
        }

        return ans;
    }
}