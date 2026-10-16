#include <bits/stdc++.h>
using namespace std;

int ask(string t) {
    cout << "? " << t << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    string t;
    bool f = true;
    for (int i = 1; i <= n; i++) {
        if (f) {
            int res = ask(t + "0");
            if (res == 1) {
                t += "0";
            }
            else {
                res = ask(t + "1");
                if (res == 1) {
                    t += "1";
                }
                else {
                    f = false;
                }
            }
        }
        else {
            int res = ask("0" + t);
            if (res == 1) {
                t = "0" + t;
            }
            else {
                res = ask("1" + t);
                if (res == 1) {
                    t = "1" + t;
                }
            }
        }
    }
    assert(t.size() == n);
    cout << "! " << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
