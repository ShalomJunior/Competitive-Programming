#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, x; cin >> a >> b >> x;
    char f = '0', s = '1';
    if (a < b) swap(f, s);
    string ans;
    for (int i = 0; i < x + 1; i++) {
        if (i & 1) {
            ans += s;
            s == '0' ? a-- : b--;
        }
        else {
            ans += f;
            f == '0' ? a-- : b--;
        }
    }
    if (a) {
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '0') {
                ans = ans.substr(0, i) + string(a, '0') + ans.substr(i, ans.size() - i);
                break;
            }
        }
    }

    if (b) {
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '1') {
                ans = ans.substr(0, i) + string(b, '1') + ans.substr(i, ans.size() - i);
                break;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}