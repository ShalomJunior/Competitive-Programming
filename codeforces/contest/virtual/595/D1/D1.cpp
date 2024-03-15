#include <bits/stdc++.h>
#define Mine vector<set<int>>
using namespace std;

int get(int n) {
    int i = 0;
    while ((1 << i) < n) i++;
    return 1 << i;
}

Mine build(vector<int>& a) {
    int N = a.size();
    Mine ans(2 * N);
    for (int i = 0; i < N; i++) {
        ans[i + N].insert(a[i]);
    }
    for (int i = N - 1; i > 0; i--) {
        ans[i].insert(ans[2 * i].begin(), ans[2 * i].end());
        ans[i].insert(ans[2 * i + 1].begin(), ans[2 * i + 1].end());
    }
    return ans;
}

void update(int i, int N, int v, vector<int>& a, Mine& vec) {
    int former = a[i - N];
    bool b = true;
    int last;
    while (i) {
        if (b) {
            vec[i].erase(former);
            a[i - N] = v;
            b = false;
        }
        else {
            last & 1 ? last-- : last++;
            if (!vec[last].count(former)) {
                vec[i].erase(former);
            }
        }
        vec[i].insert(v);
        last = i;
        i /= 2;
    }
}

int query(int l, int r, Mine& vec) {
    set<int> ans;
    while (l <= r) {
        if (l & 1) ans.insert(vec[l].begin(), vec[l].end()), l++;
        if (r % 2 == 0) ans.insert(vec[r].begin(), vec[r].end()), r--;
        l /= 2, r /= 2;
    }
    ans.erase(-1);
    return ans.size();
}

void solve() {
    string s; cin >> s;
    int n = s.length();
    int N = get(n);
    vector<int> a(N, -1);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - 'a';
    }
    Mine vec = build(a);
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; char c; cin >> i >> c;
            --i;
            update(i + N, N, c - 'a', a, vec);
        }
        else {
            int l, r; cin >> l >> r;
            --l, --r;
            cout << query(l + N, r + N, vec) << endl;
        }
    }
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << 'f' - 'a' << endl;
    solve();
}