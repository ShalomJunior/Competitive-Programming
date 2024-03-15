#include <bits/stdc++.h>
using namespace std;

void low(string& s) {
    for (auto& c : s) c = tolower(c);
}

void solve() {
    int n, m; cin >> n >> m;
    cin.ignore();
    vector<set<string>> dic(n);
    for (int i = 0; i < n; i++) {
        string line, w;
        getline(cin, line);
        istringstream is(line);
        while (is >> w) {
            low(w);
            dic[i].insert(w);
        }
    }
    cin.ignore();
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        string line, w;
        getline(cin, line);
        istringstream is(line);
        while (is >> w) {
            low(w);
            s[i] = w;
        }
    }
    map<int, char> h;
    for (int i = 0; i < m; i++) {
        bool done = false;
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (dic[k].count(s[i]) && dic[k].count(s[j])) {
                    if (!h.count(k)) {
                        int z = h.size();
                        if (z < 'X' - 'A') {
                            h[k] = 'A' + z;
                        }
                        else {
                            h[k] = 'A' + z + 1;
                        }
                    }
                    cout << h[k];
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        if (!done) cout << "X";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}