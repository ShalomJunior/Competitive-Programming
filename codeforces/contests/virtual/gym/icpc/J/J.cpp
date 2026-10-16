#include <bits/stdc++.h>
using namespace std;

const int N = 5;
const string S = "ABCDE";
void solve() {
    vector<string> a(N);
    for (auto& s : a) {
        cin >> s;
        if (s[1] == '>') swap(s[0], s[2]);
    }
    vector<int> o(N);
    iota(o.begin(), o.end(), 0);
    do {
        string p;
        map<char, int> h;
        for (int j = 0; j < N; j++) {
            p += S[o[j]];
            h[S[o[j]]] = j;
        }
        bool f = true;
        for (auto& s : a) {
            if (h[s[0]] > h[s[2]]) {
                f = false;
            }
        }
        if (f) {
            cout << p << endl;
            return;
        }
    } while (next_permutation(o.begin(), o.end()));
    cout << "impossible" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}