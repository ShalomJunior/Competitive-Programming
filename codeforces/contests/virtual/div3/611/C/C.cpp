#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for (auto& c : f) {
        cin >> c;
        c--;
    }
    set<int> from, to;
    for (int i = 0; i < n; i++) to.insert(i);
    for (int i = 0; i < n; i++) {
        if (f[i] == -1) {
            from.insert(i);
        }
        else {
            to.erase(f[i]);
        }
    }
    vector<int> both;
    for (int i = 0; i < n; i++) {
        if (from.count(i) && to.count(i)) {
            both.push_back(i);
            from.erase(i);
            to.erase(i);
        }
    }
    int m = both.size();
    if (m == 1) {
        f[both[0]] = *to.begin();
        f[*from.begin()] = both[0];
        to.erase(to.begin());
        from.erase(from.begin());
    }
    else if (m >= 2) {
        both.push_back(both[0]);
        for (int i = 0; i < m; i++) {
            f[both[i]] = both[i + 1];
            from.erase(both[i]);
            to.erase(both[i + 1]);
        }
    }
    for (auto& c : from) {
        f[c] = *to.begin();
        to.erase(to.begin());
    }
    for (int i = 0; i < n; i++) cout << f[i] + 1 << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for (auto& c : f) {
        cin >> c;
        c--;
    }
    set<int> from, to;
    for (int i = 0; i < n; i++) to.insert(i);
    for (int i = 0; i < n; i++) {
        if (f[i] == -1) {
            from.insert(i);
        }
        else {
            to.erase(f[i]);
        }
    }
    cerr << from.size() << endl;
    for (auto& c : from) cerr << c << "->";

    cerr << endl;

    cerr << to.size() << endl;
    for (auto& c : to) cerr << c << " | ";
    cerr << endl;
    vector<int> both;
    for (int i = 0; i < n; i++) {
        if (from.count(i) && to.count(i)) {
            both.push_back(i);
            from.erase(i);
            to.erase(i);
        }
    }
    int m = both.size();
    cerr << "m = " << m << endl;
    if (m == 1) {
        f[both[0]] = *to.begin();
        f[*from.begin()] = both[0];
    }
    else if (m >= 2) {
        both.push_back(both[0]);
        for (int i = 0; i < m; i++) {
            f[both[i]] = both[i + 1];
            from.erase(both[i]);
            to.erase(both[i + 1]);
        }
    }
    for (auto& c : from) {
        cerr << "c = " << c << endl;
        cerr << to.size() << endl;
        f[c] = *to.begin();
        to.erase(to.begin());
    }
    for (int i = 0; i < n; i++) cout << f[i] + 1 << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/