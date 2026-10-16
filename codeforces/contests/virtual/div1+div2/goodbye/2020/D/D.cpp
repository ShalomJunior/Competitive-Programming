#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto& c : w) cin >> c;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> deg(n);
    for (int i = 0; i < n; i++) deg[i] = adj[i].size();
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int& i, const int& j) {
        return w[i] > w[j];
        });
    int j = 0;
    int tot = accumulate(w.begin(), w.end(), 0LL);
    for (int i = 1; i < n; i++) {
        while (deg[o[j]] == 0) {
            assert(j < n);
            j++;
        }
        if (i > 1) {
            tot += w[o[j]];
            deg[o[j]]--;
        }
        else {
            for (int i = 0; i < n; i++) deg[i]--;
        }
        cout << tot << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}



/*
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto& c : w) cin >> c;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> deg(n);
    for (int i = 0; i < n; i++) deg[i] = adj[i].size();
    for (auto& c : deg) cerr << c << "->";
    cerr << endl;
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int& i, const int& j) {
        return w[i] > w[j];
        });
    int j = 0;
    int tot = accumulate(w.begin(), w.end(), 0LL);
    for (int i = 1; i < n; i++) {
        while (deg[o[j]] == 0) {
            cerr << "j = " << j << "  " << o[j] << endl;
            assert(j < n);
            for (auto& c : adj[o[j]]) {
                //deg[c]--;
                cerr << c << " " << deg[c] << endl;
            }cerr << endl;
            j++;
        }
        if (i > 1) {
            tot += w[o[j]];
            cerr << "#" << w[o[j]] << endl;
            deg[o[j]]--;
        }
        else {
            for (int i = 0; i < n; i++) deg[i]--;
        }
        cout << tot << " << endl;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}*/