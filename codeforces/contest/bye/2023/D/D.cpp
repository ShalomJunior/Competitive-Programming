#include <bits/stdc++.h>
using namespace std;

const int N = 4e5;
const int M = 20;

vector<map<string, vector<long long>>> h(M);
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= min(n, M - 1); i++) {
        for (auto& [k, v] : h[i]) {
            if (v.size() >= n && (n - i) % 2 == 0) {
                string suff(n - i, '0');
                for (int l = 0; l < n; l++) {
                    cout << v[l] << suff << " ";
                }
                cout << endl;
                return;
            }
        }
    }
}

void init() {
    for (int i = 1; i <= N; i++) {
        long long x = 1LL * i * i;
        string s = to_string(x);
        sort(s.begin(), s.end());
        h[s.length()][s].push_back(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--)solve();
}
