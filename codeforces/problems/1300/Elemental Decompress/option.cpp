#include <bits/stdc++.h>

using namespace std;

void out(vector<int>& v) {
    for (auto& c : v)
        cout << c << " ";
    cout << endl;
}

void solve() {
    int n; cin >> n;
    set<int> p, q;
    for (int i = 0; i < n; i++) {
        p.insert(i + 1);
        q.insert(i + 1);
    }

    vector<int> ansp(n), ansq(n);
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        if (p.find(v) != p.end()) {
            ansp[i] = v;
            p.erase(v);
        }
        else if (q.find(v) != q.end()) {
            ansq[i] = v;
            q.erase(v);
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ansp[i] == 0) {
            auto it = lower_bound(p.begin(), p.end(), ansq[i]);
            if (it == p.begin()) {
                cout << "NO" << endl;
                return;
            }
            else {
                it = prev(it);
                ansp[i] = *it;
                p.erase(it);
            }
        }

        if (ansq[i] == 0) {
            auto it = lower_bound(q.begin(), q.end(), ansp[i]);
            if (it == p.begin()) {
                cout << "NO" << endl;
                return;
            }
            else {
                it = prev(it);
                ansq[i] = *it;
                q.erase(it);
            }
        }
    }
    cout << "YES" << endl;
    out(ansp);
    out(ansq);
}
int main() {
    int t; cin >> t;
    while (t--)solve();
}