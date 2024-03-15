#include <bits/stdc++.h>

using namespace std;

int main() {
    int  n; cin >> n;
    vector<int> v(n);
    for (auto& c : v) cin >> c;
    set<int> s(v.begin(), v.end());
    cout << s.size() << endl;
}