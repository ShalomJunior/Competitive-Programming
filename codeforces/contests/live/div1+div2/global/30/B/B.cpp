#include <bits/stdc++.h>
using namespace std;

const int N = 35;
void solve() {
    int n;
    cin >> n;
    vector<int> e, o;
    for (int i = 0; i < n;i++) {
        int x;
        cin >> x;
        x & 1 ? o.push_back(x) : e.push_back(x);
    }
    int z = e.size();
    if (z >= 2) {
        cout << e[0] << " " << e[1] << endl;
        return;
    }
    if (z == 1) {
        for (auto& c : o) {
            if (e[0] > c && (e[0] % c) % 2 == 0) {
                cout << c << " " << e[0] << endl;
                return;
            }
        }
    }
    if (n >= N) {
        for (int i = 0; i + 1 < o.size(); i++) {
            if (o[i] * 2 > o[i + 1]) {
                cout << o[i] << " " << o[i + 1] << endl;
                return;
            }
        }
    }
    else {
        for (int i = 0; i < o.size(); i++) {
            for (int j = i + 1; j < o.size(); j++) {
                if ((o[j] % o[i]) % 2 == 0) {
                    cout << o[i] << " " << o[j] << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}