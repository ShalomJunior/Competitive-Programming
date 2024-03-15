#include <bits/stdc++.h>

using namespace std;

bool vec(vector<int> a, vector<int>b, int idx) {
    if (idx == a.size() || idx == b.size()) return a.size() != idx;
    if (a[idx] != b[idx]) return a[idx] > b[idx];
    return vec(a, b, idx + 1);
}

bool official(pair<string, pair<int, vector<int>>> x, pair<string, pair<int, vector<int>>> y) {
    auto a = x.second;
    auto b = y.second;
    if (a.first != b.first) return a.first > b.first;
    return vec(a.second, b.second, 0);
}

int main() {
    vector<int> points = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };
    int t, n; cin >> t >> n;
    unordered_map <string, pair<int, vector<int>>> mp;

    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        for (int j = 0; j < r; j++) {
            string s; cin >> s;
            mp[s].first += points[j];
            mp[s].second[j]++;
        }
    }

    vector <pair<string, pair<int, vector<int>>>> temp(mp.begin(), mp.end());
    sort(temp.begin(), temp.end(), official);

    cout << temp[0].first << endl;
}