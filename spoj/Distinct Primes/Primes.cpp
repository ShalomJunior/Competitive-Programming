#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

const int P = 20;

vector<int> primes;
vector<int> ans;
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)return false;
    }
    return true;
}

void fd() {
    for (int i = 2; (int)primes.size() < P; i++) {
        if (is_prime(i))primes.push_back(i);
    }
}

void compute() {
    vector<int> idx(P);
    fill(idx.end() - 3, idx.end(), 1);

    do {
        int curr = 1;
        for (int i = 0; i < P; i++) {
            if (idx[i])curr *= primes[i];
        }
        ans.push_back(curr);
    } while (next_permutation(idx.begin(), idx.end()));

    sort(ans.begin(), ans.end());
}

void solve() {
    int n; cin >> n;
    cout << ans[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fd(); compute();
    cout << ans.size() << endl;
    int t; cin >> t;
    while (t--)solve();
}