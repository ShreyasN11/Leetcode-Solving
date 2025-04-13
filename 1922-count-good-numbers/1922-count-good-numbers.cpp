class Solution {
public:
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
            }
            return result;
    }
    int countGoodNumbers(long long n) {
        long long res = 1;
        long long MOD = 1e9 +7;
        
        long long res1 = modPow(5, (n+1)/2, MOD);
        long long res2 = modPow(4, n/2, MOD);

        res = (res1 * res2) % MOD;
        return res;
    }
};

        // for(long long i=1; i<=n; i++){
        //     if(i%2){
        //         res*=5; res%=MOD;
        //     }
        //     else{
        //          res*=4; res%=MOD;
        //     }
        // }