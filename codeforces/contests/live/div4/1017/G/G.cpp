#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int q;
    cin >> q;
    deque<int> dq;
    bool flag = true;
    int n = 0;
    int sum = 0;
    int tot = 0;
    while (q--) {
        int s;
        cin >> s;
        if (s == 1) {
            int val = -1;
            if (flag) {
                val = dq.back();
                dq.push_front(dq.back());
                dq.pop_back();
            }
            else {
                val = dq.front();
                dq.push_back(dq.front());
                dq.pop_front();
            }
            tot += sum - n * val;
        }
        else if (s == 2) {
            flag = !flag;
            tot = (n + 1) * sum - tot;
        }
        else if (s == 3) {
            int k;
            cin >> k;
            sum += k;
            flag ? dq.push_back(k) : dq.push_front(k);
            n++;
            tot += k * n;
        }
        else {
            assert(false);
        }
        cout << tot << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
