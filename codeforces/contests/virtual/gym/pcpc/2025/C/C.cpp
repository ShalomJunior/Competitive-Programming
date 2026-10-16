#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;
string S, T;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int x = INF;
    for (int i = 0; i < 3; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] != S[i + j]) curr++;
        }
        x = min(x, curr);
    }
    int y = INF;
    for (int i = 0; i < 3; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] != T[i + j]) curr++;
        }
        y = min(y, curr);
    }
    if (x == y) {
        cout << "FAKE";
    }
    else {
        if (x < y) {
            cout << "mit " << x;
        }
        else {
            cout << "mti " << y;
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (S.size() < N) S += "mit";
    while (T.size() < N) T += "mti";
    solve();
}
