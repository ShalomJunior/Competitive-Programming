#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    vector<Mine> vec;
    for (auto& [x, nb] : cnt) {
        vec.push_back({ x, nb });
    }
    sort(vec.begin(), vec.end(), [&](Mine& a, Mine& b) {
        return a.S > b.S;
        });
    int m = vec.size();
    int L = 1, R = n;
    auto check = [&](int mid) {
        int sum = 0;
        for (int i = 0; i < min(k, m); i++) {
            sum += vec[i].S / mid;
        }
        return sum >= k;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        bool f = check(mid);
        if (f) {
            if (L == mid) {
                check(R) ? L = R : R = L;
            }
            else L = mid;
        }
        else R = mid - 1;
    }
    for (int i = 0, sum = 0; i < min(k, m) && sum < k; i++) {
        int r = k - sum;
        int have = vec[i].S / L;
        for (int j = 0; j < min(r, have); j++) {
            cout << vec[i].F << " ";
        }
        sum += min(r, have);
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}