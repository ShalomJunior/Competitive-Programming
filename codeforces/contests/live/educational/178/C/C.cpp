#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 2) {
        cout << (s[0] == 'A' ? "Alice" : "Bob") << endl;
        return;
    }
    set<int> A, B;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            A.insert(i + 1);
        }
        else {
            B.insert(i + 1);
        }
    }
    if (A.count(n) && (A.count(1) || A.count(n - 1))) {
        cout << "Alice";
    }
    else if (B.count(n) && (B.count(1) || B.count(n - 1))) {
        cout << "Bob";
    }
    else {
        if (A.size() == 1 && *A.begin() == n) {
            cout << "Bob";
        }
        else if (B.size() == 1 && *B.begin() == n) {
            cout << "Alice";
        }
        else {
            cout << "Bob";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
