#include <bits/stdc++.h>
using namespace std;

vector<int> qr = { 0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1, };
/*
int query(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}
*/
int query(int a, int b, int c) {
    int t = 0, f = 0;
    for (auto& e : { a, b, c }) {
        qr[e] ? t++ : f++;
    }
    return t > f;
}

void solve() {
    int n; cin >> n;
    vector<int> q(n), ans(n, -1);
    int a, b;
    for (int i = 0; i < n - 2; i++) {
        q[i] = query(i, i + 1, i + 2);
        if (i > 0) {
            if (q[i] != q[i - 1]) {
                a = i - 1, b = i + 2;
                ans[a] = q[i - 1], ans[b] = q[i];
            }
        }
    }
    int tries = 8;
    for (int i = n / 2; tries && i < n; i++) {
        if (i == a || i == b)continue;
        ans[i] = query(a, b, i);
        tries--;
    }
    for (int i = n / 2; i >= 0; i--) {
        if (ans[i] == -1) {
            if (q[i]) {

            }
            else {

            }
        }
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

