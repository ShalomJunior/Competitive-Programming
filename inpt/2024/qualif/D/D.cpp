#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, int> h;
    vector<string> order;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!h.count(s)) order.push_back(s);
        h[s]++;
    }
    for (auto& s : order) {
        cout << s << " " << h[s] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

