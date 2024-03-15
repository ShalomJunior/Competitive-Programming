#include <bits/stdc++.h>
using namespace std;

int query(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    vector<int> ans(n);
    int a, b, last = query(0, 1, 2);
    for (int i = 1; i < n - 2; i++) {
        int r = query(i, i + 1, i + 2);
        if (r != last) {
            a = i - 1, b = i + 2;
            ans[a] = last, ans[b] = r;
            break;
        }
        else last = r;
    }
    for (int i = 0; i < n; i++) {
        if (i == a || i == b)continue;
        ans[i] = query(a, b, i);
    }
    int k = count(ans.begin(), ans.end(), 0);
    cout << "! " << k << " ";
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

