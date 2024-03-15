#include <bits/stdc++.h>

using namespace std;

void out(vector<int>& v) {
    for (auto& c : v)
        cout << c << " ";
    cout << endl;
}

void solve() {
    int n; cin >> n;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        if (v > 0) pos++;
        else neg++;
    }

    vector<int> mx;
    for (int i = 1; i <= pos; i++) {
        mx.push_back(i);
    }
    for (int i = pos - 1; ;i--) {
        if (mx.size() == n)break;
        mx.push_back(i);
    }

    vector<int> mn;
    for (int i = 1; i <= 2 * min(pos, neg); i++) {
        if (i & 1)mn.push_back(1);
        else mn.push_back(0);
    }

    for (int i = 1; ; i++) {
        if (mn.size() == n) break;
        mn.push_back(i);
    }

    out(mx);
    out(mn);

}
int main() {
    int t; cin >> t;
    while (t--)solve();
}