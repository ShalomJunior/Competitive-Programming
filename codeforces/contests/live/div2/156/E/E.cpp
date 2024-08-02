#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& c : A) cin >> c;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    map<int, map<string, bool>> h;
    int all = 0;
    int cnt = 0;
    do {
        string s;
        int sum = 0;
        for (int a = 1; a <= n; a++) {
            sum += A[p[a - 1]];
            s += to_string(p[a - 1]);
            auto t = s;
            sort(t.begin(), t.end());
            bool flag = true;
            for (int i = 0; i < a; i++) flag &= (t[i] == char('0' + i));
            if (a <= k && flag && a != n) continue;
            if (!h[a][s]) {
                all += sum;
                cnt++;
                h[a][s] = true;
            }
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << all << " " << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
