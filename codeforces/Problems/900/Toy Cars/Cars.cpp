#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    int ans = 0;
    vector<int> cars;
    for (int i = 0; i < n; i++) {
        bool val = true;
        for (int j = 0; j < n; j++) {
            int v; cin >> v;
            if (v == 1 || v == 3) {
                val = false;
            }
        }
        if (val) {
            cars.push_back(i + 1);
            ans++;
        }
    }

    cout << ans << endl;
    if (ans) {
        for (auto& c : cars)
            cout << c << " ";
        cout << endl;
    }
}