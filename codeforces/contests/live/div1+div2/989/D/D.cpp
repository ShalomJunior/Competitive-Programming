#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] != 1) idx.push_back(i);
    }
    int x = 0;
    if (!idx.empty()) {
        x = idx.back();
        idx.pop_back();
    }
    else {
        while (a[x] != 1) x++;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n && !idx.empty(); i++) {
        if (b[i] == 1 && a[i] != 1) {
            int j = idx.back();
            idx.pop_back();
            swap(a[i], a[j]);
            ans.push_back({ i , j });
        }
    }
    map<int, map<int, vector<int>>> mp;
    for (int i = 0; i < n; i++) mp[a[i]][b[i]].push_back(i);
    int z1 = mp[0][2].size();
    int z2 = mp[2][0].size();
    cerr << z1 << " -> " << z2 << endl;
    //assert(z1 == z2);
    while (!mp[0][2].empty() && !mp[2][0].empty()) {
        int i = mp[2][0].back();
        int j = mp[0][2].back();
        mp[0][2].pop_back();
        mp[2][0].pop_back();
        swap(a[i], a[j]);
        ans.push_back({ j , x });
        ans.push_back({ i , j });
        if (mp[0][2].empty() && mp[2][0].empty()) {
            ans.push_back({ i , x });
            swap(a[i], a[j]);
        }
        x = i;
    }
    int k = ans.size();
    stringstream ss;
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0) {
            k++;
            ss << ans[i].first << " " << ans[i].second << endl;
        }
    }
    assert(k <= n);
    for (auto& c : a) cerr << c << " ";
    cerr << endl;
    if (!is_sorted(a.begin(), a.end())) {
        vector<int> t;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && b[i] != 1) t.push_back(i);
        }
    }
    //assert(is_sorted(a.begin(), a.end()));
    cout << k << endl;
    cout << ss.str();cerr << endl;
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

bool check(pair<int, int> a, pair<int, int> b) {
    if (a.first > a.second) swap(a.first, a.second);
    if (b.first > b.second) swap(b.first, b.second);
    return a != b;
}
void solve() {
    cout << endl;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] != 1) idx.push_back(i);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (b[i] == 1 && a[i] != 1) {
            int j = idx.back();
            idx.pop_back();
            swap(a[i], a[j]);
            ans.push_back({ i + 1, j + 1 });
        }
    }
    int x = 0;
    while (b[x] != 1) x++;
    map<int, map<int, vector<int>>> mp;
    for (int i = 0; i < n; i++) mp[a[i]][b[i]].push_back(i);
    int z1 = mp[0][2].size();
    int z2 = mp[2][0].size();
    assert(z1 == z2);
    while (!mp[0][2].empty() && !mp[2][0].empty()) {
        int i = mp[2][0].back();
        int j = mp[0][2].back();
        mp[0][2].pop_back();
        mp[2][0].pop_back();
        swap(a[i], a[j]);
        ans.push_back({ i + 1, x + 1 });
        ans.push_back({ i + 1, j + 1 });
        if (mp[0][2].empty()) {
            ans.push_back({ i + 1, x + 1 });
        }
        x = j;
    }
    int k = 0;
    stringstream ss;
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0 || check(ans[i], ans[i - 1])) {
            k++;
            ss << ans[i].first << " " << ans[i].second << endl;
        }
    }
    cout << k << " |" << n << endl;
    cout << ss.str() << endl;;
    cout << "end" << endl;
    assert(is_sorted(a.begin(), a.end()));
    assert(k <= n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
*/