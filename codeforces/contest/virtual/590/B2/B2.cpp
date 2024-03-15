#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    set<int> s;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!s.count(x)) {
            dq.push_front(x);
            s.insert(x);
            if (s.size() > k) {
                s.erase(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << min(k, (int)dq.size()) << endl;
    while (!dq.empty() && k) {
        cout << dq.front() << " ";
        dq.pop_front();
        k--;
    }
    cout << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}