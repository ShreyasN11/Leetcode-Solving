#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sieve(int limit) {
        vector<bool> is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= limit; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = sieve(1000);
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i] - prev;
            int index = lower_bound(primes.begin(), primes.end(), x) - primes.begin() - 1;
            if (index >= 0) {
                prev = nums[i] - primes[index];
            } else {
                if (nums[i] <= prev) {
                    return false;
                }
                prev = nums[i];
            }
        }
        return true;
    }
};
