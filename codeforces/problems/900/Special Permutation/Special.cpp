#include <bits/stdc++.h>

using namespace std;

void out(vector<int>& v) {
    for (auto& c : v)
        cout << c << " ";
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(i + 1);

    vector<int> left, right;
    left.push_back(a);
    s.erase(a);
    right.push_back(b);
    s.erase(b);

    for (int i = n; left.size() != n / 2 && i > a; i--) {
        if (s.find(i) != s.end()) {
            left.push_back(i);
            s.erase(i);
        }
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it > b) {
            cout << -1 << endl;
            return;
        }
        else right.push_back(*it);
    }

    if (left.size() != n / 2 || right.size() != n / 2) {
        cout << -1 << endl;
        return;
    }
    out(left);
    out(right);
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}