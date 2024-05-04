#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = abs(a[i]);
    vector<int> b(n, 1);
    set<int> id;
    for (int i = 0; i < n; i++) id.insert(i);
    if (n & 1) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (a[j] != a[0]) {
                int k = (j == 1 ? 2 : 1);
                if (abs(a[0] + a[j]) > N || abs(a[0] + a[j]) == 0) b[j] *= -1;
                int s = abs(a[0] + b[j] * a[j]);
                int m = lcm(s, c[k]);
                b[0] *= (m / s);
                b[j] *= (m / s);
                b[k] *= (m / c[k]);
                if (signbit(a[0] * b[0] + a[j] * b[j]) == signbit(a[k])) b[k] *= -1;
                for (auto c : { 0, j , k }) id.erase(c);
                flag = true;
                break;
            }
        }
        if (!flag) {
            b[2] *= -2;
            for (auto j : { 0, 1, 2 }) id.erase(j);
        }
    }
    for (auto it = id.begin(); it != id.end(); it++) {
        int i = *it; it++;
        int j = *it;
        int m = lcm(c[i], c[j]);
        b[i] *= (m / c[i]);
        b[j] *= (m / c[j]);
        if (signbit(a[i]) == signbit(a[j])) b[i] *= -1;
    }
    for (auto& c : b) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}