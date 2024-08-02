#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5;
int f(int n) {
    return n * (n + 1) / 2;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    auto b = a;
    auto work = [&]() {
        for (auto& c : b) ans += c;
        set<int> uno, dos;
        dos.insert(0);
        for (int i = 0; i < n; i++) {
            if (uno.count(b[i])) dos.insert(b[i]);
            int next = *prev(dos.end());
            uno.insert(b[i]);
            b[i] = next;
        }
        };
    for (int i = 0; i < N; i++) work();
    map<int, int> cnt;
    for (auto& c : b) cnt[c]++;
    vector<pair<int, int>> p;
    for (auto& [k, v] : cnt) p.push_back({ k, v });
    int m = p.size();
    int s = 0;
    for (int i = m - 1; i >= 0; i--) {
        ans += p[i].first * p[i].second * s;
        ans += p[i].first * f(p[i].second);
        s += p[i].second;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}



// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// const int N = 5;
// int f(int n) {
//     return n * (n + 1) / 2;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (auto& c : a) cin >> c;
//     int ans = 0;
//     auto b = a;
//     auto work = [&]() {
//         for (auto& c : b) ans += c;
//         set<int> uno, dos;
//         dos.insert(0);
//         for (int i = 0; i < n; i++) {
//             if (uno.count(b[i])) dos.insert(b[i]);
//             int next = *prev(dos.end());
//             uno.insert(b[i]);
//             b[i] = next;
//         }
//         for (auto& c : b) cerr << c << " -> ";
//         cerr << endl;
//         };
//     for (int i = 0; i < N; i++) work();
//     map<int, int> cnt;
//     for (auto& c : b) cnt[c]++;
//     vector<pair<int, int>> p;
//     for (auto& [k, v] : cnt) {
//         p.push_back({ k, v });
//         cerr << k << " -> " << v << endl;
//     }
//     int m = p.size();
//     cerr << "m = " << m << endl;
//     int s = 0;
//     for (int i = m - 1; i >= 0; i--) {
//         ans += p[i].first * p[i].second * s;
//         ans += p[i].first * f(p[i].second);
//         s += p[i].second;
//     }
//     cout << ans << endl;
//     cerr << endl;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; cin >> t;
//     while (t--)solve();
// }