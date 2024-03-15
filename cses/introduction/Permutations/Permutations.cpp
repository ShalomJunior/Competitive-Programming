#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    if (n > 1 && n < 4) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    vector<int> ans;
    for (int i = 2; i <= n; i += 2)
        ans.push_back(i);

    for (int i = 1; i <= n; i += 2)
        ans.push_back(i);

    for (auto& c : ans) cout << c << " ";
    cout << endl;
}