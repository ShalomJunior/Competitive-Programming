#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int N = 1 << n;
    vector<int> a(N);
    iota(a.begin(), a.end(), 1);
    auto work = [&](vector<int> v) {
        int m = v.size();
        vector<int> ans;
        for (int i = 0; i < m; i += 4) {
            int res = ask(v[i], v[i + 2]);
            if (res == 0) {
                res = ask(v[i + 1], v[i + 3]);
                ans.push_back(res == 1 ? v[i + 1] : v[i + 3]);
            }
            else if (res == 1) {
                res = ask(v[i], v[i + 3]);
                ans.push_back(res == 1 ? v[i] : v[i + 3]);
            }
            else {
                res = ask(v[i + 1], v[i + 2]);
                ans.push_back(res == 1 ? v[i + 1] : v[i + 2]);
            }
        }
        return ans;
        };
    while (a.size() >= 4) a = work(a);
    int z = a.size();
    if (z == 1) {
        cout << "! " << a[0];
    }
    else if (z == 2) {
        int res = ask(a[0], a[1]);
        assert(res);
        cout << "! " << (res == 1 ? a[0] : a[1]) << endl;
    }
    else {
        assert(false);
    }
    cout << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}