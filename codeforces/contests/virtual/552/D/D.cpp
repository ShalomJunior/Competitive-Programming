#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, b, a; cin >> n >> b >> a;
    vector<int> x(n);
    for (auto& c : x) cin >> c;
    int M = a;
    for (int i = 0; i < n; i++) {
        if (x[i]) {
            if (a != M && b) b--, a++;
            else if (a) a--;
            else {
                cout << i << endl;
                return;
            }
        }
        else {
            if (a) a--;
            else if (b) b--;
            else {
                cout << i << endl;
                return;
            }
        }
    }
    cout << n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}