#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto b = a;
    for (auto& row : b) {
        sort(row.begin(), row.end());
    }
    set<int> cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                cols.insert(j);
            }
        }
    }
    if (cols.empty()) {
        cout << "1 1" << endl;
        return;
    }
    else if (cols.size() >= 4) {
        cout << -1 << endl;
        return;
    }
    vector<int> p(cols.begin(), cols.end());
    set<pair<int, int>> done;
    auto check = [&](int i, int j) {
        auto g = a;
        for (int r = 0; r < n; r++) {
            swap(g[r][i], g[r][j]);
        }
        for (auto& row : g) {
            if (!is_sorted(row.begin(), row.end())) return false;
        }
        return true;
        };
    do {
        pair<int, int> lead = { p[0], p[1] };
        if (!done.count(lead)) {
            done.insert(lead);
            if (check(p[0], p[1])) {
                cout << p[0] + 1 << " " << p[1] + 1 << endl;
                return;
            }
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << -1 << endl;
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

void solve() {
    cerr << endl;
    cerr << "solve" << endl;
    int n, m;
    cin >> n >> m;
    cerr << "n: " << n << endl;
    cerr << "m: " << m << endl;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto b = a;
    for (auto& row : b) {
        sort(row.begin(), row.end());
    }
    set<int> cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cerr << a[i][j] << " -> " << b[i][j] << endl;
            if (a[i][j] != b[i][j]) {
                cols.insert(j);
            }
        }
    }
    if (cols.empty()) {
        cout << "1 1" << endl;
        return;
    }
    else if (cols.size() >= 4) {
        cout << -1 << endl;
        return;
    }
    vector<int> p(cols.begin(), cols.end());
    set<pair<int, int>> done;
    auto check = [&](int i, int j) {
        cerr << i << ", " << j << endl;
        auto g = a;
        for (int r = 0; r < n; r++) {
            swap(g[r][i], g[r][j]);
        }
        for (auto& row : g) {
            if (!is_sorted(row.begin(), row.end())) return false;
        }
        return true;
        };
    cerr << "#" << cols.size() << endl;
    assert(cols.size() > 1);
    do {
        cerr << "in " << endl;
        pair<int, int> lead = { p[0], p[1] };
        if (!done.count(lead)) {
            done.insert(lead);
            if (check(p[0], p[1])) {
                cout << p[0] + 1 << " " << p[1] + 1 << endl;
                return;
            }
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}*/