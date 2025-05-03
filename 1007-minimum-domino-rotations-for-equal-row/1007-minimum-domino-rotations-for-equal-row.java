class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int n = tops.length;
        int m = bottoms.length;
        if(m != n) return -1;
        int a1 = tops[0];
        int a2 = bottoms[0];

        int mini = Integer.MAX_VALUE;
        int c1 = 0; int c2 = 0;
        for(int i=0; i<n; i++){
            if(tops[i] != a1 && bottoms[i] != a1){
                c1 = Integer.MAX_VALUE; c2 = Integer.MAX_VALUE;
                break;
            }
            else if(tops[i] != a1) c1++;
            else if(bottoms[i] != a1) c2++;
        }
        mini = Math.min(c1,c2);
        c1=0; c2=0;
         for(int i=0; i<n; i++){
            if(tops[i] != a2 && bottoms[i] != a2){
                c1 = Integer.MAX_VALUE; c2 = Integer.MAX_VALUE;
                break;
            }
            else if(tops[i] != a2) c1++;
            else if(bottoms[i] != a2) c2++;
        }
        mini = Math.min(mini,Math.min(c1,c2));
        if(mini == Integer.MAX_VALUE) return -1;
        else return mini;

    }
}