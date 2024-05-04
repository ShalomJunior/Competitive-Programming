#include <bits/stdc++.h>

using namespace std;

pair<int, int> db(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 2) return { i, -1 };
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[i] > v[j] && v[i] < 2 * v[j])
                return { i, j };
            else if (v[i] < v[j] && v[j] < 2 * v[i])
                return { j, i };
        }
    }

    return { 0, 0 };
}

bool valid(vector<int>& v) {
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) cnt++;
    }

    return !(cnt > 0 && cnt < v.size());
}

void solve() {
    cout << "TESTCASE" << endl;
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v)
        cin >> c;

    if (!valid(v)) {
        cout << -1 << endl;
        return;
    }

    auto p = db(v);
    if (p.first == 0 && p.second == 0) {
        cout << 0 << endl;
        return;
    }

    stringstream out;
    int nb = 0;
    if (p.second != -1) {
        out << p.first + 1 << " " << p.second + 1 << endl;
        v[p.first] = ceil((double)v[p.first] / v[p.second]);
        nb++;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] > 2) {
            while (v[i] != 2) {
                nb++;
                out << i + 1 << " " << p.first + 1 << endl;
                v[i] = ceil((double)v[i] / 2);
            }
        }
    }

    cout << nb << endl;
    cout << out.str();

}


int main() {
    int t; cin >> t;
    while (t--)solve();
}