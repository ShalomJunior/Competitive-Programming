#include <bits/stdc++.h>
using namespace std;

void solve() {
    int L, P;
    cin >> L >> P;
    string ans = "Az";
    for (int i = 0; i < L - 3; i++) ans += 'u';
    ans += 'z';
    cout << "[";
    for (int i = 1; i <= L; i++) {
        if (i <= (L * float(P) / 100)) {
            cout << ans[i - 1];
        }
        else {
            cout << "-";
        }
    }
    cout << "]";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

/*

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, p;
    cin >> l >> p;
    string ans = "Az";
    for (int i = 0; i < l - 3; i++) ans += 'u';
    ans += 'z';
    //cerr << "ans = " << ans << endl;
    cout << "[";
    int m = ans.size();
    for (int i = 0; i < ans.size(); i++) {
        //cerr << i + 1 << " " << m << endl;
        //cerr << floor(100.0 * (i + 1) / m) << " " << p << endl;
        if (floor(100.0 * (i + 1) / m) <= p) {
            cout << ans[i];
        }
        else {
            cout << "-";
        }
    }
    cout << "]";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/