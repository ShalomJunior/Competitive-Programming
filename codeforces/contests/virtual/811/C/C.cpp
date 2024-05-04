#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int D = 10;
vector<int> ans(N, INT_MAX);
void prepare() {
    for (int i = 1; i <= D; i++) {
        vector<int> nums(D);
        iota(nums.begin(), nums.end(), 0);
        vector<int> idx(D);
        fill(idx.end() - i, idx.end(), 1);
        do {
            int sm = 0;
            vector<int> temp;
            for (int j = 0; j < D; j++) {
                if (idx[j]) {
                    temp.push_back(nums[j]);
                    sm += temp.back();
                }
            }
            sort(temp.rbegin(), temp.rend());
            int key = 0;
            for (int j = 0; j < temp.size(); j++) {
                key += temp[j] * pow(10, j);
            }
            ans[sm] = min(ans[sm], key);
        } while (next_permutation(idx.begin(), idx.end()));
    }
}

void solve() {
    int n; cin >> n;
    cout << ans[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}