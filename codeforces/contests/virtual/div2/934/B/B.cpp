#include <bits/stdc++.h>
using namespace std;

vector<int> get(vector<int>& a) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<int> f, g;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && a[i] == a[i + 1]) {
            g.push_back(a[i]);
            i++;
        }
        else f.push_back(a[i]);
    }
    int s = -1;
    if (f.size() % 2) {
        s = f.back();
        f.pop_back();
    }
    for (auto& c : g) {
        f.push_back(c);
        f.push_back(c);
    }
    if (s != -1)f.push_back(s);
    return f;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& c : a)cin >> c;
    for (auto& c : b)cin >> c;
    auto x = get(a);
    auto y = get(b);
    for (int i = 0; i < 2 * k; i++)cout << x[i] << " ";
    cout << endl;
    for (int i = 0; i < 2 * k; i++)cout << y[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}