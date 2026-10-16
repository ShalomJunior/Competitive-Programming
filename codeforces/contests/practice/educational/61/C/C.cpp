#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
template<typename T>
class sum {
public:
    int n;
    vector<T> pref;
    sum(vector<T>& arr) {
        n = arr.size();
        pref.resize(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    T query(int l, int r) {
        assert(l >= 0 && r < n);
        return pref[r] - (l ? pref[l - 1] : 0);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(q);
    int L = N;
    int R = 0;
    for (auto& [l, r] : a) {
        cin >> l >> r;
        L = min({ L, l, r });
        R = max({ R, l, r });
    }
    sort(a.begin(), a.end());
    vector<int> cnt(R + 1);
    multiset<int> ms;
    for (int i = L, j = 0; i <= R; i++) {
        while (!ms.empty() && *ms.begin() < i) ms.erase(*ms.begin());
        while (j < q && a[j].first == i) {
            ms.insert(a[j].second);
            j++;
        }
        cnt[i] = ms.size();
    }
    int ans = 0;
    for (int i = 0; i < q; i++) {
        vector<int> c = cnt;
        vector<int> uno(R + 1);
        vector<int> dos(R + 1);
        for (int j = L; j <= R; j++) {
            int val = cnt[j];
            if (a[i].first <= j && j <= a[i].second) val--;
            if (val > 0) uno[j]++;
            if (val > 1) dos[j]++;
        }
        sum<int> X(uno);
        sum<int> Y(dos);
        for (int j = i + 1; j < q; j++) {
            auto [l, r] = a[j];
            int curr = X.query(L, R) - X.query(l, r) + Y.query(l, r);
            ans = max(ans, curr);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
