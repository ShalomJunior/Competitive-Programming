#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> red, vector<int> blue) {
    int p = 1;
    for (auto& c : red) {
        if (c > p) return false;
        ++p;
    }
    for (auto& c : blue) {
        if (c < p) return false;
        ++p;
    }
    return true;
}

bool g(vector<int> red, vector<int> blue) {
    int p = 1;
    for (auto& c : blue) {
        if (c < p) return false;
        ++p;
    }
    for (auto& c : red) {
        if (c > p) return false;
        ++p;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    string s; cin >> s;
    vector<int> red, blue;
    for (int i = 0; i < n; i++) {
        s[i] == 'R' ? red.push_back(a[i]) : blue.push_back(a[i]);
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    cout << (f(red, blue) || g(red, blue) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}