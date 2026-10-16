#include <bits/stdc++.h>
using namespace std;

const int K = 1e4;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int k = 0;
    stringstream ss;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                if (b[i] < b[j]) {
                    cout << -1 << endl;
                    return;
                }
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                k++;
                ss << i + 1 << " " << j + 1 << endl;
            }
            else if (a[i] == a[j]) {
                if (b[i] > b[j]) {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    k++;
                    ss << i + 1 << " " << j + 1 << endl;
                }
            }
        }
    }
    assert(k <= K);
    if (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())) {
        cout << k << endl;
        cout << ss.str() << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
