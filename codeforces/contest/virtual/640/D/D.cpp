#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    deque<int> dq(n);
    for (auto& c : dq) cin >> c;
    int a = dq.front(), b = 0, moves = 1, last = dq.front();
    dq.pop_front();
    while (!dq.empty()) {
        int sum = 0;
        while (!dq.empty() && sum <= last) {
            sum += (moves & 1 ? dq.back() : dq.front());
            moves & 1 ? dq.pop_back() : dq.pop_front();
        }
        moves & 1 ? b += sum : a += sum;
        last = sum;
        moves++;
    }
    cout << moves << " " << a << " " << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}