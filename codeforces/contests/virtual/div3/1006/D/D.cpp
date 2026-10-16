#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mn = INF;
    int L = 0;
    int R = 0;
    for (int i = 0; i < n; i++) {
        int f = 0;
        for (int j = i; j < n; j++) {
            if (a[j] < a[i])
                f--;
            else if (a[j] > a[i])
                f++;
            if (f < mn) {
                mn = f;
                L = i;
                R = j;
            }
        }
    }
    cout << L + 1 << " " << R + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}