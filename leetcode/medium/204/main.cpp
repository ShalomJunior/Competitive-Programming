#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = prime[n] = false;
        for (int i = 2; i < n; i++) {
            if (!prime[i]) continue;
            for (long long j = 1LL * i * i; j < n; j += i) prime[j] = false;
        }
        return count(prime.begin(), prime.end(), true);
    }
};