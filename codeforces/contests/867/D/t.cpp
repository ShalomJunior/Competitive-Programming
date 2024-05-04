#include <bits/stdc++.h>

using namespace std;


void out(vector<int>& v) {
    for (auto& c : v)cout << c << " ";
    cout << endl;
}

bool is(vector<int>& v) {
    int n = (int)v.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i) {
            ans[i] = (ans[i - 1] + v[i]) % n;
        }
        else {
            ans[i] = v[i] % n;
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        if (ans[i] != i)return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    vector<int> v(N);
    iota(v.begin(), v.end(), 1);
    do {
        if (is(v)) {
            cout << "Yes" << " "; out(v);
        }
    } while (next_permutation(v.begin(), v.end()));

}