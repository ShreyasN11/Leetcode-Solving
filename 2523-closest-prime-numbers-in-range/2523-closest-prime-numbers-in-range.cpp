class Solution {
public:
    vector<bool> sieve(int n){
        vector<bool>is_prime(n+1,true);
        is_prime[0] = is_prime[1] = false;
        for(int i=2; i*i<=n; i++){
            if(is_prime[i]){
                for(int j=i*i; j<=n; j+=i){
                    is_prime[j] = false;
                }
            }
        }
        return is_prime;
    }

    vector<bool>prime_range(int l, int r){
        vector<bool>prime = sieve(sqrt(r));
        vector<bool>is_prime(r-l+1, true);

        for(int i=2; i*i<=r; i++){
            if(prime[i]){
                for(int j=max(i*i, (l+i-1)/ i*i); j<=r; j+=i){
                    is_prime[j-l] = false;
                }
            }
        }
        return is_prime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool>primes = prime_range(left, right);
        int dist = INT_MAX; int index = 0;
        int i=0;
        int n = right-left+1;
        vector<int>list;
        for(int i=0; i<n; i++){
            if (primes[i]) list.push_back(left+i);
        }
        int minDist=INT_MAX;
        int p1= -1, p2= -1;

        for (int i=1; i<list.size(); i++) {
            int dist = list[i] - list[i - 1];
            if (dist < minDist) {
                minDist = dist;
                p1 = list[i - 1];
                p2 = list[i];
            }
        }

        return {p1, p2};
    }
};