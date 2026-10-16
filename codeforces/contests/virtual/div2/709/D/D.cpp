#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    a.push_back(a[0]);
    set<int> ids;
    for (int i = 0; i < 2 * n; i++) ids.insert(i);
    set<int> g;
    for (int i = 0; i < n; i++) {
        if (__gcd(a[i], a[i + 1]) == 1) {
            g.insert(i);
        }
    }
    bool flag = true;
    vector<int> ans;
    while (flag) {
        flag = false;
        int start = 0;
        while (start < n) {
            auto it = g.lower_bound(start);
            if (it == g.end()) break;
            flag = true;
            auto nxt = ids.upper_bound(*it);
            int j = *nxt;
            if (j >= n) j -= n;
            ans.push_back(j);
            ids.erase(j);
            ids.erase(j + n);
            g.erase(j);
            nxt = ids.upper_bound(*it);
            if (nxt != ids.end()) {
                int i = *nxt;
                if (i >= n) i -= n;
                if (__gcd(a[*it], a[i]) != 1) g.erase(it);
                start = *nxt;
            }
            else {
                break;
            }

        }
    }
    cout << ans.size() << " ";
    for (auto& c : ans) cout << c + 1 << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (auto& c : a) cin >> c;
//     a.push_back(a[0]);
//     set<int> ids;
//     for (int i = 0; i < 2 * n; i++) ids.insert(i);
//     set<int> g;
//     for (int i = 0; i < n; i++) {
//         if (__gcd(a[i], a[i + 1]) == 1) {
//             g.insert(i);
//         }
//     }
//     bool flag = true;
//     vector<int> ans;
//     while (flag) {
//         flag = false;
//         int start = 0;
//         while (start < n) {
//             auto it = g.lower_bound(start);
//             if (it == g.end()) break;
//             //if (ids.size() <= 2) break;
//             cerr << "left  " << a[*it] << endl;
//             flag = true;
//             auto nxt = ids.upper_bound(*it);
//             //assert(nxt != ids.end());
//             int j = *nxt;
//             if (j >= n) j -= n;
//             ans.push_back(j);
//             ids.erase(j);
//             ids.erase(j + n);
//             g.erase(j);
//             nxt = ids.upper_bound(*it);
//             if (nxt != ids.end()) {
//                 int i = *nxt;
//                 if (i >= n) i -= n;
//                 cerr << a[*it] << " -> " << a[i] << endl;
//                 if (__gcd(a[*it], a[i]) != 1) g.erase(it);
//                 start = *nxt;
//             }
//             else {
//                 cerr << "Error" << endl;
//                 break;
//             }

//         }
//     }
//     cout << ans.size() << endl;
//     for (auto& c : ans) cout << c + 1 << " ";
//     cout << endl;
//     cout << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; cin >> t;
//     while (t--)solve();
// }