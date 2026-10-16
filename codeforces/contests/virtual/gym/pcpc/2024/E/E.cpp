#include <bits/stdc++.h>
using namespace std;

const int N = 31;
struct Info {
    int val;
    int start;
    int end;
    Info() : val(-1), start(-1), end(-1) {}
    Info(int v, int s, int e) : val(v), start(s), end(e) {}
    bool operator<(const Info& o) const {
        if (val != o.val) return val < o.val;
        if (start != o.start) return start < o.start;
        return end < o.end;
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int j = n;
    deque<int> p;
    vector<int> next(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        next[i] = s[i] == '1' ? i : next[i + 1];
        if (s[i] == '0') {
            next[i] = next[i + 1];
            j = i;
        }
        else {
            next[i] = i;
            p.push_front(i);
        }
    }
    vector<Info> all;
    for (int i = 0; i < n; i++) {
        int val = 0;
        int where = next[i];
        for (int k = 0; k < N && where + k < n; k++) {
            val *= 2;
            if (s[where + k] == '1') val += 1;
            all.push_back({ val, i, where + k });
        }
    }
    sort(all.begin(), all.end());
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == 0) {
            if (j != n) {
                cout << j + 1 << " " << j + 1 << "\n";
                continue;
            }
            else {
                if (r == 0) {
                    cout << -1 << " " << -1 << "\n";
                    continue;
                }
            }
        }
        auto it = lower_bound(all.begin(), all.end(), Info(l, -1, -1));
        if (it == all.end() || it->val > r) {
            cout << -1 << " " << -1 << "\n";
            continue;
        }
        cout << it->start + 1 << " " << it->end + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}