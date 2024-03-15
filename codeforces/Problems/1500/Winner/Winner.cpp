#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    unordered_map<string, int> h;
    vector<pair<string, int>> v(n);
    for (int i = 0; i < n; i++) {
        string name; int score;
        cin >> name >> score;
        v[i] = make_pair(name, score);
        h[name] += score;
    }

    int mx = INT_MIN;

    for (auto [k, v] : h)
        mx = max(mx, v);

    unordered_map<string, int> equals;
    for (auto [k, v] : h)
        if (v == mx) equals[k] = 0;

    for (int i = 0; i < n; i++) {
        string name = v[i].first;
        int score = v[i].second;
        if (equals.find(name) != equals.end()) {
            equals[name] += score;
            if (equals[name] >= mx) {
                cout << name << endl;
                return 0;
            }
        }
    }

}