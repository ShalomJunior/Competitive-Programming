#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    list<int> l;
    unordered_map<int, list<int>::iterator> h;
    for (int i = 0; i < n;i++) {
        int v; cin >> v;
        l.push_back(v);
        h[v] = next(l.begin(), i);
    }

    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (l.front() == n / 2 - i && l.back() == n / 2 + i) {
            continue;
        }
        else {
            ans++;
            l.erase(h[n / 2 - 1]);
            l.erase(h[n / 2 + i]);

            l.push_front(n / 2 - i);
            h[n / 2 - 1] = l.begin();
            l.push_back(n / 2 + i);
            h[n / 2 + i] = prev(l.end());
            //l.erase(h);
        }
    }

    cout << ans << endl;
}

int main() {
    list<int> s = { 7, 57, 6, 5 };

    s.erase(s.begin());
    int t; cin >> t;
    while (t--)solve();
}