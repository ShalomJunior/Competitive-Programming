#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int N = 4e4;
const int INF = 1e9;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++)prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i])continue;
        primes.push_back(i);
        for (int j = i * i; j < N; j += i)prime.reset(j);
    }
}

void dec(int n, vector<Mine>& div) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            div.push_back({ 1, n });
            return;
        }
        if (n % primes[i])i++;
        else {
            Mine add = { 0, primes[i] };
            while (n % primes[i] == 0) {
                add.F++;
                n /= primes[i];
            }
            div.push_back(add);
            i++;
        }
    }
    if (n > 1) div.push_back({ 1, n });
}

void solve() {
    int n; cin >> n;
    do {
        cout << n << " ";
        if (n % 2 == 0) n /= 2;
        else {
            vector<Mine> div;
            dec(n, div);
            int d = n / div[0].S;
            n -= d;
        }
    } while (n != 1);
    cout << 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}