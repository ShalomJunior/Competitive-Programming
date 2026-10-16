#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>>& x) {
    int n = x.size();
    if (n == 0) return;
    sort(x.begin(), x.end());
    vector<pair<int, int>> temp;
    int l = x[0].first;
    int r = x[0].second;
    for (int i = 1; i < n; i++) {
        if (x[i].first > r) {
            temp.push_back({ l, r });
            l = x[i].first;
            r = x[i].second;
        }
        else {
            r = max(r, x[i].second);
        }
    }
    temp.push_back({ l, r });
    x = temp;
}

void print(vector<int>& x) {
    for (auto& c : x) cout << c << " ";
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    int L = 1, R = n;
    for (auto& [l, r] : p) {
        cin >> l >> r;
        L = max(L, l);
        R = min(R, r);
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    if (L <= R) {
        L--;
        if (L != 0) {
            swap(ans[0], ans[L]);
        }
        print(ans);
        return;
    }
    auto a = p;
    merge(a);
    if (a.size() == 1 && a[0].first == 1 && a[0].second == n) {
        int z = -1;
        for (int i = 1; i + 1 <= n; i++) {
            int x = 0;
            int y = 0;
            for (auto& [l, r] : p) {
                if (l == r) x++, y++;
                if (l == i && r > i + 1) x++;
                if (l < i && r == i + 1) y++;
            }
            if (x == 0 && y == 0) {
                z = i;
                break;
            }
        }
        assert(z != -1);
        z--;
        if (z != 0) {
            swap(ans[0], ans[z]);
            swap(ans[1], ans[z + 1]);
        }
        print(ans);
        return;
    }
    else {
        int z = a[0].first == 1 ? a[0].second + 1 : a[0].first;
        z--;
        if (z != 0) swap(ans[0], ans[z]);
        print(ans);
        return;
    }
    assert(false);
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

void merge(vector<pair<int, int>>& x) {
    int n = x.size();
    if (n == 0) return;
    sort(x.begin(), x.end());
    vector<pair<int, int>> temp;
    int l = x[0].first;
    int r = x[0].second;
    for (int i = 1; i < n; i++) {
        if (x[i].first > r) {
            temp.push_back({ l, r });
            l = x[i].first;
            r = x[i].second;
        }
        else {
            r = max(r, x[i].second);
        }
    }
    temp.push_back({ l, r });
    x = temp;
}

void print(vector<int>& x) {
    for (auto& c : x) cout << c << " ";
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    int L = 1, R = n;
    for (auto& [l, r] : p) {
        cin >> l >> r;
        L = max(L, l);
        R = min(R, r);
    }
    cout << L << " -> " << R << endl;
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    if (L <= R) {
        L--;
        if (L != 0) {
            cout << L << " " << n << endl;
            swap(ans[0], ans[L]);
        }
        print(ans);
        return;
    }
    auto a = p;
    merge(a);
    if (a.size() == 1 && a[0].first == 1 && a[0].second == n) {
        int z = -1;
        for (int i = 1; i + 1 <= n; i++) {
            int x = 0;
            int y = 0;
            for (auto& [l, r] : p) {
                if (l == i && r > i + 1) x++;
                if (l < i && r == i + 1) y++;
            }
            if (x == 0 && y == 0) {
                z = i;
                break;
            }
        }
        assert(z != -1);
        z--;
        if (z != 0) {
            swap(ans[0], ans[z]);
            swap(ans[1], ans[z + 1]);
        }
        print(ans);
        return;
    }
    else {
        cout << "in" << endl;
        int z = a[0].first == 1 ? a[0].second + 1 : a[0].first;
        z--;
        if (z != 0) swap(ans[0], ans[z]);
        print(ans);
        return;
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
*/