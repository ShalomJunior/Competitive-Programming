#include <bits/stdc++.h>

using namespace std;

void out(vector<int>& v) {
    for (auto& c : v)
        cout << c << " ";
    cout << endl;
}

bool done(vector<int>& fll, vector<int>& emp, set<int>& semp) {
    int n = fll.size();
    set<pair<int, int>> temp;
    for (int i = 0; i < n; i++) {
        if (emp[i] == 0)
            temp.insert({ fll[i], i });
    }

    while (!semp.empty()) {
        auto curr = *prev(temp.end());
        if (*prev(semp.end()) > curr.first) {
            return false;
        }
        emp[curr.second] = *prev(semp.end());
        temp.erase(curr);
        semp.erase(prev(semp.end()));
    }
    return true;
}

void solve() {
    int n; cin >> n;
    set<int> p, q;
    int i;
    for (i = 0; i < n; i++) {
        p.insert(i + 1);
        q.insert(i + 1);
    }

    bool end = false;
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
            end = true;
        }
    }

    if (end) {
        cout << "NO" << endl;
        return;
    }

    if (!done(ansq, ansp, p) || !done(ansp, ansq, q)) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        out(ansp);
        out(ansq);
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}