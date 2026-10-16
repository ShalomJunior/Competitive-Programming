#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    int cnt = 0;
    stringstream ss;
    for (int i = 0; i < n; i++) {
        int p = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[p]) {
                p = j;
            }
        }
        while (p != i) {
            cnt++;
            ss << 1 << " " << p << endl;
            swap(a[p], a[p - 1]);
            p--;
        }
    }
    for (int i = 0; i < n; i++) {
        int p = i;
        for (int j = i; j < n; j++) {
            if (b[j] < b[p]) {
                p = j;
            }
        }
        while (p != i) {
            cnt++;
            ss << 2 << " " << p << endl;
            swap(b[p], b[p - 1]);
            p--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cnt++;
            ss << 3 << " " << i + 1 << endl;
            swap(a[i], b[i]);
        }
    }
    cout << cnt << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}