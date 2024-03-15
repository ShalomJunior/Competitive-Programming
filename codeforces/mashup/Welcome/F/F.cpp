#include <bits/stdc++.h>

using namespace std;

using mine = pair<string, pair<int, int>>;

bool compare(mine a, mine b) {
    if (a.second.first != b.second.first)
        return a.second.first > b.second.first;
    else {
        if (a.second.second != b.second.second)
            return a.second.second < b.second.second;
    }

    return a.first < b.first;
}

int main() {
    int n; cin >> n;
    vector<mine> v(n);
    for (int i = 0; i < n; i++) {
        string s; int e, w;
        cin >> s >> e >> w;
        v[i] = make_pair(s, make_pair(e, w));
    }

    sort(v.begin(), v.end(), compare);

    for (auto& pers : v)
        cout << pers.first << endl;
}