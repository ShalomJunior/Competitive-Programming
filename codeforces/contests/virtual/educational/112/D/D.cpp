#include <bits/stdc++.h>
using namespace std;

const int N = 3;
void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<vector<int>>> cnt(n, vector<vector<int>>(N, vector<int>(N)));
    for (int i = 0; i < n; i++) {
        if (i) cnt[i] = cnt[i - 1];
        cnt[i][i % N][s[i] - 'a']++;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        auto v = cnt[r];
        if (l > 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    v[i][j] -= cnt[l - 1][i][j];
                }
            }
        }
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        int ans = 1e9;
        do {
            int curr = 0;
            for (int i = 0; i < N; i++) {
                int tot = 0;
                for (auto& c : v[i])tot += c;
                curr += tot - v[i][p[i]];
            }
            ans = min(ans, curr);
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*

#include <bits/stdc++.h>
using namespace std;

const int N = 3;
void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<vector<int>>> cnt(n, vector<vector<int>>(N, vector<int>(N)));
    for (int i = 0; i < n; i++) {
        if (i) cnt[i] = cnt[i - 1];
        cnt[i][i % N][s[i] - 'a']++;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        auto v = cnt[r];
        if (l > 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    v[i][j] -= cnt[l - 1][i][j];
                }
            }
        }
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        int ans = 1e9;
        do {
            //for (auto& c : p) cerr << c << " -> ";
            ///cerr << endl;
            int curr = 0;
            for (int i = 0; i < N; i++) {
                //cerr << "i = " << i << endl;
                int tot = 0;
                for (auto& c : v[i])tot += c;
                //cerr << "tot " << tot << endl;
                curr += tot - v[i][p[i]];
            }
            //cerr << "curr << " << curr << endl;
            ans = min(ans, curr);
            //cerr << endl;
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << endl << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
*/