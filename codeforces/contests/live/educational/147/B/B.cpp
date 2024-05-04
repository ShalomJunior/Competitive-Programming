#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a)cin >> c;
    for (auto& c : b)cin >> c;

    vector<pair<int, int>> poss;
    int start = 0, end = 0;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] > b[i + 1]) {
            poss.push_back(mp(start, end));
            start = i + 1;
            end = i + 1;
        }
        else {
            end++;
        }
    }

    poss.push_back(mp(start, end));
    int L = 0; int R = 0;
    for (auto p : poss) {
        if (p.S - p.F > R - L) {
            L = p.F;
            R = p.S;
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