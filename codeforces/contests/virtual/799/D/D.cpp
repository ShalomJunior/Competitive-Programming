#include <bits/stdc++.h>
using namespace std;

const int N = 1440;
set<int> is;
void prepare() {
    for (int i = 0; i < N; i++) {
        int h = i / 60, m = i % 60;
        string sh = ((h > 9) ? "" : "0") + to_string(h);
        string sm = ((m > 9) ? "" : "0") + to_string(m);
        reverse(sh.begin(), sh.end());
        if (sh == sm) is.insert(i);
    }
}

void solve() {
    string t; int x; cin >> t >> x;
    string sh = t.substr(0, 2);
    string sm = t.substr(3, 2);
    int start = stoi(sh) * 60 + stoi(sm);
    int ans = 0;
    set<int> done;
    for (int i = start; i < N; i = (i + x) % N) {
        if (done.count(i))break;
        else done.insert(i);
        if (is.count(i))ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}