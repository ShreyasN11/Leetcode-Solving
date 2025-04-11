class Solution {
    static boolean check(int x){
        int temp = x; int digits = 0;
        while(x > 0){
            digits++;
            x/=10;
        }
        int left = 0; int right=0;
        for(int i=0; i<digits/2; i++){
            left += temp%10;
            temp/=10;
        }
        for(int i=0; i<digits/2; i++){
            right += temp%10;
            temp/=10;
        }
        return left == right;
    }
    public int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            if((i>9 && i<100) || (i>999 && i<10000)){
                if(check(i)) count++;
            }
        }
        return count;
    }
}