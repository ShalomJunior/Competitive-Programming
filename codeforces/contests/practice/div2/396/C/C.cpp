#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 26;
const int MOD = 1e9 + 7;
const int INF = 1e18;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(N);
    for (auto& c : a) cin >> c;
    s = "#" + s + "?";
    vector<int> dp1(n + 1);
    vector<int> dp2(n + 1, INF);
    dp1[0] = 1;
    dp2[0] = 0;
    int len = 1;
    for (int i = 1; i <= n; i++) {
        int mn = n;
        for (int j = i; j > 0; j--) {
            mn = min(mn, a[s[j] - 'a']);
            if (mn < i - j + 1) break;
            len = max(len, i - j + 1);
            dp1[i] += dp1[j - 1];
            dp2[i] = min(dp2[i], 1 + dp2[j - 1]);
        }
        dp1[i] %= MOD;
    }
    cout << dp1[n] << " " << len << " " << dp2[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 26;
const int MOD = 1e9 + 7;
const int INF = 1e18;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(N);
    for (auto& c : a) cin >> c;
    s = "#" + s + "?";
    vector<int> dp1(n + 1);
    vector<int> dp2(n + 1, INF);
    dp1[0] = 1;
    dp2[0] = 0;
    int len = 1;
    for (int i = 1; i <= n; i++) {
        int mn = n;
        for (int j = i; j > 0; j--) {
            mn = min(mn, a[s[j] - 'a']);
            cerr << "mn  = " << mn << endl;
            if (mn < i - j + 1) break;
            len = max(len, i - j + 1);
            cerr << dp1[i] << " @" << endl;
            dp1[i] += dp1[j - 1];
            cerr << dp1[i] << " }" << endl;

            dp2[i] = min(dp2[i], 1 + dp2[j - 1]);
        }
        cerr << "edn->" << endl;
    }
    for (auto& c : dp1) cerr << c << " ";
    cerr << endl;
    for (auto& c : dp2) cerr << c << " ";
    cerr << endl;

    cerr << "edn" << endl;
    cout << dp1[n] << " " << len << " " << dp2[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
*/