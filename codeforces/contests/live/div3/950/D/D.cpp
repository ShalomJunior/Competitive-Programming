#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> g;
    for (int i = 0; i + 1 < n; i++) {
        g.push_back(__gcd(a[i], a[i + 1]));
    }
    if (is_sorted(g.begin(), g.end()) ||
        is_sorted(g.begin() + 1, g.end()) ||
        is_sorted(g.begin(), g.end() - 1)) {
        cout << "YES" << endl;
        return;
    }
    vector<bool> L(n), R(n);
    L[0] = true;
    for (int i = 1; i < n - 1; i++) {
        L[i] = L[i - 1] & (g[i - 1] <= g[i]);
    }
    R[n - 2] = R[n - 1] = true;
    for (int i = n - 3; i >= 0; i--) {
        R[i] = R[i + 1] & (g[i] <= g[i + 1]);
    }
    for (int i = 1; i < n - 1; i++) {
        int ng = __gcd(a[i - 1], a[i + 1]);
        bool x = i == 1 || g[i - 2] <= ng && L[i - 2];
        bool y = i == n - 2 || ng <= g[i + 1] && R[i + 1];
        if (x & y) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


/*


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> g;
    for (int i = 0; i + 1 < n; i++) {
        g.push_back(__gcd(a[i], a[i + 1]));
    }
    for (auto& c : g) cerr << c << " ";
    cerr << endl;
    if (is_sorted(g.begin(), g.end()) ||
        is_sorted(g.begin() + 1, g.end()) ||
        is_sorted(g.begin(), g.end() - 1)) {
        cout << "#YES" << endl;
        return;
    }
    vector<bool> L(n), R(n);
    L[0] = true;
    for (int i = 1; i < n - 1; i++) {
        L[i] = L[i - 1] & (g[i - 1] <= g[i]);
    }
    R[n - 2] = R[n - 1] = true;
    for (int i = n - 3; i >= 0; i--) {
        R[i] = R[i + 1] & (g[i] <= g[i + 1]);
    }
    for (int i = 1; i < n - 1; i++) {
        int ng = __gcd(a[i - 1], a[i + 1]);
        bool x = i == 1 || g[i - 2] <= ng && L[i - 2];
        if (i > 1) {
            cerr << (L[i - 1] ? "|Y" : "|N") << endl;
        }
        bool y = i == n - 2 || ng <= g[i + 1] && R[i + 1];
        if (i < n - 2) {
            cerr << (R[i + 1] ? "Y" : "N") << endl;
        }
        cerr << g[i - 1] << " " << ng << endl;
        cerr << ng << " " << g[i + 1] << endl;
        if (x & y) {
            cerr << "i = " << i << endl;
            cout << "YES" << endl;
            return;
        }
        cerr << endl;
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
*/