// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     string s, t;
//     cin >> s >> t;
//     if (s[0] != t[0]) {
//         cout << -1 << endl;
//         return;
//     }
//     int cnt = 0;
//     stringstream ss;
//     while (s != t) {
//         cnt++;
//         if (cnt > k) {
//             cout << -1 << endl;
//             return;
//         }
//         int j = n - 1;
//         string ns = s;
//         bool bad = false;
//         for (int i = n - 1; i > 0; i--) {
//             if (s[i] == t[i] && !bad) continue;
//             j = min(j, i - 1);
//             while (j >= 0 && s[j] != t[i]) j--;
//             if (j < 0) {
//                 cout << -1 << endl;
//                 return;
//             }
//             ns[j + 1] = s[j];
//             if (ns[i] != t[i]) bad = true;
//         }
//         swap(s, ns);
//         ss << s << endl;
//     }
//     if (cnt > k) {
//         cout << -1 << endl;
//         return;
//     }
//     cout << cnt << endl;
//     cout << ss.str();
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; cin >> t;
//     while (t--)solve();
// }


#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> idx(N);
    for (int i = 0; i < n; i++) {
        int j = t[i] - 'a';
        idx[j].push_back(i);
    }
    if (s[0] != t[0]) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    stringstream ss;
    while (s != t && cnt++ <= k) {
        int j = n - 1;
        string ns = s;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == t[i]) {
                if (j < i) {
                    while (j >= 0 && s[j] != t[i]) j--;
                    if (j < 0) {
                        cout << -1 << endl;
                        return;
                    }
                    ns[j + 1] = s[j];
                }
            }
            else {
                j = min(j, i);
                while (j >= 0 && s[j] != t[i]) j--;
                if (j < 0) {
                    cout << -1 << endl;
                    return;
                }
                ns[j + 1] = s[j];
            }
        }
        swap(s, ns);
        ss << s << endl;
    }
    if (cnt > k) {
        cout << -1 << endl;
        return;
    }
    cout << cnt << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}