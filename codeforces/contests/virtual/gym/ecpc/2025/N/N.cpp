#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> p(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i > 0) {
            p[i]--;
            adj[p[i]].push_back(i);
        }
    }
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> t(n);
    for (auto& x : t) cin >> x;
    function<int(int)> g = [&](int r) {
        int rem = 0;
        if (t[r] == 3) {
            rem += c - a[r];
            a[r] = 0;
        }
        for (auto& v : adj[r]) rem += g(v);
        int can = min(rem, a[r]);
        a[r] -= can;
        rem -= can;
        return rem;
        };
    function<void(int, map<int, int>&)> f = [&](int r, map<int, int>& dis) {
        if (t[r] == 3)
            return;
        if (t[r] == 2) {
            dis[a[r]]++;
            return;
        }
        for (auto& v : adj[r]) {
            map<int, int> child;
            f(v, child);
            if (child.size() > dis.size())
                swap(child, dis);
            for (auto& [key, val] : child)
                dis[key] += val;
        }

        while (a[r] && !dis.empty()) {
            vector<int> del;
            int sz = dis.size();
            if (sz == 1) {
                int z = dis.begin()->first;
                int k = dis.begin()->second;
                int add = a[r] / k;
                int res = a[r] % k;
                map<int, int> h;
                if (res) {
                    h[z + add] = k - res;
                    h[z + add + 1] = res;
                }
                else {
                    h[z + add] = k;
                }
                dis = h;
                a[r] = 0;
            }
            else if (sz > 1) {
                for (auto& [k, v] : dis) {
                    if (a[r] == 0) break;
                    int z = prev(dis.end())->first;
                    if (k == z) break;
                    int need = z - k;
                    int can = a[r] / need;
                    if (can >= v) {
                        dis[z] += v;
                        a[r] -= need * v;
                        del.push_back(k);
                    }
                    else {
                        dis[z] += can;
                        dis[k] -= can;
                        a[r] -= need * can;
                        dis[k + a[r]]++;
                        a[r] = 0;
                        if (--dis[k] == 0) del.push_back(k);
                    }
                }
                for (auto& x : del) dis.erase(x);
            }
        }
        };
    g(0);
    map<int, int> ans;
    f(0, ans);
    int mx = 0;
    for (auto& [k, v] : ans) mx = max(mx, k);
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            mx += a[i];
        }
    }
    cout << mx << endl;
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

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> p(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i > 0) {
            p[i]--;
            adj[p[i]].push_back(i);
        }
    }
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> t(n);
    for (auto& x : t) cin >> x;
    function<int(int)> g = [&](int r) {
        cerr << "root " << r << endl;
        int rem = 0;
        if (t[r] == 3) {
            rem += c - a[r];
            a[r] = 0;
        }
        for (auto& v : adj[r]) rem += g(v);
        int can = min(rem, a[r]);
        a[r] -= can;
        rem += can;
        return rem;
        };

    function<void(int, map<int, int>&)> f = [&](int r, map<int, int>& dis) {
        if (t[r] == 2) {
            dis[a[r]]++;
            return;
        }
        for (auto& v : adj[r]) f(v, dis);
        if (a[r]) {
            vector<int> del;
            if (dis.size() > 1) {
                for (auto& [k, v] : dis) {
                    if (a[r] == 0) break;
                    int z = prev(dis.end())->first;
                    if (k == z) break;
                    int need = z - k;
                    int can = a[r] / need;
                    if (can >= v) {
                        dis[z] += v;
                        a[r] -= need * v;
                        del.push_back(k);
                    }
                    else {
                        dis[z] += can;
                        dis[k] -= can;
                        a[r] -= need * can;
                        dis[k + a[r]]++;
                        if (--dis[k] == 0) del.push_back(k);
                    }
                }
                for (auto& x : del) dis.erase(x);
            }
            if (dis.size() == 1 && a[r]) {
                int z = dis.begin()->first;
                int k = dis.begin()->second;
                int add = a[r] / k;
                int res = a[r] % k;
                map<int, int> h;
                if (res) {
                    h[z + add] = k - res;
                    h[z + add + 1] = res;
                }
                else {
                    h[z + add] = k;
                }
                dis = h;
            }
        }
        cerr << "rt = " << r << endl;

        for (auto& [k, v] : dis) cerr << k << " -> " << v << endl;
        };

    cerr << "start" << endl;
    g(0);
    cerr << "finished" << endl;
    for (auto& x : a) cerr << x << " ";
    cerr << endl;
    map<int, int> ans;
    f(0, ans);
    int mx = 0;
    for (auto& [k, v] : ans) mx = max(mx, k);
    cout << mx << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
*/