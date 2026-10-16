#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> from;
    for (int i = 0; i < n; i++) from.insert(i);
    auto to = from;
    vector<int> b(n, -2);
    for (int i = 0; i < n; i++) {
        a[i]--;
        if (to.count(a[i])) {
            b[i] = a[i];
            to.erase(a[i]);
            from.erase(i);
        }
    }
    int m = from.size();
    if (m == 1) {
        int u = *from.begin();
        int v = *to.begin();
        if (u == v) {
            int j = find(b.begin(), b.end(), a[u]) - b.begin();
            b[u] = a[u];
            b[j] = v;
        }
        else {
            b[u] = v;
        }
    }
    else if (m > 1) {
        vector<int> x(from.begin(), from.end());
        vector<int> y(to.begin(), to.end());
        vector<int> same;
        for (int i = 0; i < m; i++) {
            if (x[i] == y[i]) {
                same.push_back(i);
            }
        }
        int k = same.size();
        for (int i = 0; i + 1 < k; i += 2) {
            int l = same[i];
            int r = same[i + 1];
            swap(y[l], y[r]);
        }
        if (k & 1) {
            bool g = false;
            int l = same.back();
            for (int i = 0; i < m; i++) {
                if (i != l) {
                    if (x[i] != y[l] && x[l] != y[i]) {
                        swap(y[i], y[l]);
                        g = true;
                        break;
                    }
                }
            }
            assert(g);
        }
        for (int i = 0; i < m; i++) b[x[i]] = y[i];
    }
    else {}
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += a[i] == b[i];
    cout << cnt << endl;
    for (auto& c : b) cout << c + 1 << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}


/*
#include<bits/stdc++.h>
using namespace std;


void dbg(set<int>s, string p) {
    for (auto& c : s) cerr << c << p;
    cerr << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> from;
    for (int i = 0; i < n; i++) from.insert(i);
    auto to = from;
    vector<int> b(n, -2);
    for (int i = 0; i < n; i++) {
        a[i]--;
        if (to.count(a[i])) {
            b[i] = a[i];
            to.erase(a[i]);
            from.erase(i);
        }
    }
    int m = from.size();

    if (m == 1) {
        int u = *from.begin();
        int v = *to.begin();
        if (u == v) {
            int j = find(b.begin(), b.end(), a[u]) - b.begin();
            b[u] = a[u];
            b[j] = v;
        }
        else {
            b[u] = v;
        }
    }
    else {
        dbg(from, " # ");
        dbg(to, " ð ");
        vector<int> x(from.begin(), from.end());
        vector<int> y(to.begin(), to.end());
        vector<int> same;
        for (int i = 0; i < m; i++) {
            if (x[i] == y[i]) {
                same.push_back(i);
            }
        }
        int k = same.size();
        for (int i = 0; i + 1 < k; i += 2) {
            int l = same[i];
            int r = same[i + 1];
            swap(y[l], y[r]);
        }
        if (k & 1) {
            bool g = false;
            int l = same.back();
            for (int i = 0; i < k; i++) {
                if (i != l) {
                    if (x[i] != y[l] && x[l] != y[i]) {
                        swap(y[i], y[l]);
                        g = true;
                        break;
                    }
                }
            }
            assert(g);
        }
        for (int i = 0; i < m; i++) b[x[i]] = y[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += a[i] == b[i];
    cout << cnt << endl;
    for (auto& c : b) cout << c + 1 << " ";
    cout << endl;
    cerr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}*/