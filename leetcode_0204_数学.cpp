class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n,true);
        int res = 0;
        for(int i=2;i<n;i++) {
            if(!primes[i]) {
                continue;
            }
            int k= n/i + (n%i?1:0);
            for(int j=i;j<k;j++) {
                primes[i*j] = false;
            }
            res++;
        }
        return res;
    }
};