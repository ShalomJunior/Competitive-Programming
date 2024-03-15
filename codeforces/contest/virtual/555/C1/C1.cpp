#include <bits/stdc++.h>
using namespace std;

string go(deque<int> dq, int last) {
    string s;
    while (!dq.empty()) {
        if (dq[0] < dq.back()) {
            if (dq[0] > last) {
                s += 'L';
                last = dq[0];
                dq.pop_front();
            }
            else if (dq.back() > last) {
                s += 'R';
                last = dq.back();
                dq.pop_back();
            }
            else break;
        }
        else if (dq[0] == dq.back()) {
            if (dq[0] > last) {
                if (dq.size() == 1) {
                    if (dq[0] > last) s += 'L';
                    break;
                }
                auto x = dq, y = dq;
                x.pop_front(); y.pop_back();
                string sx = s + 'L' + go(x, dq[0]);
                string sy = s + 'R' + go(y, dq[0]);
                s = sx.size() > sy.size() ? sx : sy;
            }
            break;
        }
        else {
            if (dq.back() > last) {
                s += 'R';
                last = dq.back();
                dq.pop_back();
            }
            else if (dq[0] > last) {
                s += 'L';
                last = dq[0];
                dq.pop_front();
            }
            else break;
        }
    }
    return s;
}

void solve() {
    int n; cin >> n;
    deque<int> dq(n);
    for (auto& c : dq) cin >> c;
    auto s = go(dq, 0);
    cout << s.size() << endl;
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}