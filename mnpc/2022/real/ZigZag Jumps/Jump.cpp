#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    set<int> s;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> db;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v[i] = a;
        s.insert(a);
        db[a].push(i);
    }

    int path[n][2];
    for (int i = 0; i < n - 1; i++) {
        int c = v[i];
        db[c].pop();
        if (db[c].empty())s.erase(c);

        auto inf = s.lower_bound(c);
        if (inf == s.begin())path[i][0] = -1;
        else path[i][0] = db[*(--inf)].top();

        auto sup = s.upper_bound(c);
        if (sup == s.end()) path[i][1] = -1;
        else path[i][1] = db[*sup].top();
    }

    vector<int> odd(n, -1), even(n, -1);
    odd[n - 1] = 1; even[n - 1] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (odd[i] != -1 && even[i] != -1)continue;
        int pos = i, nb = 0;
        bool can = false;
        vector<int> idx;
        while (pos != -1) {
            nb++;
            bool b = false;
            if (nb & 1) b |= odd[pos] != -1;
            else b |= even[pos] != -1;

            if (b || pos == n - 1) {
                can |= (pos == n - 1);
                can |= (nb & 1) ? odd[pos] : even[pos];
                break;
            }
            else {
                idx.push_back(pos);
                pos = path[pos][nb & 1];
            }
        }

        for (int i = 0; i < (int)idx.size(); i++) {
            if (i & 1)even[idx[i]] = can;
            else odd[idx[i]] = can;
        }
    }

    cout << count(odd.begin(), odd.end(), 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}