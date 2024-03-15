#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans[x - 1] = i + 1;
    }

    for (auto& v : ans)
        cout << v << " ";
    cout << endl;
}