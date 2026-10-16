#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n;
    cin >> n;
    int L = -INF;
    int R = INF;
    for (int i = 0; i < n; i++) {
        string s;
        int a;
        cin >> s >> a;
        int l = -INF;
        int r = INF;
        if (s == ">") {
            l = a + 1;
        }
        else if (s == "<") {
            r = a - 1;
        }
        else if (s == ">=") {
            l = a;
        }
        else if (s == "<=") {
            r = a;
        }
        L = max(L, l);
        R = min(R, r);
    }
    if (L > R) {
        cout << "IMPOSSIBLE";
    }
    else if (L == R) {
        cout << L;
    }
    else {
        cout << "NOT UNIQUE";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}