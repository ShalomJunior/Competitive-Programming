#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, std::less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> Tree;

const int INF = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    Tree ms;
    for (int i = 0; i < n; i++) ms.insert({ a[i], i });
    int ans = 0;
    int e = 0;
    for (int i = 0; i < n; i++) {
        ms.erase(ms.lower_bound({ a[i], 0 }));
        if (e == k) {
            ans += a[i] + e;
            continue;
        }
        int z = ms.size();
        int r = k - (e + 1);
        if (z <= r) {
            e++;
        }
        else {
            int mx = ms.find_by_order(z - (r + 1))->first;
            if (a[i] > mx + 1) {
                e++;
            }
            else {
                ans += a[i] + e;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}


/*

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, std::less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> Tree;

const int INF = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    Tree ms;
    for (int i = 0; i < n; i++) ms.insert({ a[i], i });
    int ans = 0;
    int e = 0;
    for (int i = 0; i < n; i++) {
        cerr << "-<>" << a[i] << endl;
        ms.erase(ms.lower_bound({ a[i], 0 }));
        if (e == k) {
            ans += a[i] + e;
            continue;
        }
        int z = ms.size();
        int r = k - (e + 1);
        cerr << z << " -> " << r << endl;
        if (z <= r) {
            e++;
        }
        else {
            cerr << "in" << endl;
            int mx = ms.find_by_order(z - (r + 1))->first;
            cerr << "mx = " << mx << endl;
            if (a[i] > mx + 1) {
                e++;
            }
            else {
                ans += a[i] + e;
            }
        }
    }
    cout << ans << endl << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}*/