#include <bits/stdc++.h>
using namespace std;

const int N = 31;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> h;
    for (auto& c : a)cin >> c, h[c]++;
    int bad = 0;
    for (int i = 0; i < n; i++) {
        bool b = false;
        for (int j = 0; j < N; j++) {
            int x = (1 << j) - a[i];
            if (x == a[i]) {
                if (h[x] > 1) b = true;
            }
            else if (h[x]) b = true;
        }
        if (!b) bad++;
    }
    cout << bad << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}