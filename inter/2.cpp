#include <bits/stdc++.h>
using namespace std;

vector<string> closest(vector<string>& s) {
    int M = 255;
    vector<string> ans = { "Black", "White", "Red", "Green", "Blue" };
    auto calc = [&](int a, int b, int c) {
        return a * a + b * b + c * c;
        };
    vector<string> res;
    for (auto& str : s) {
        string sr = str.substr(0, 8);
        string sg = str.substr(8, 8);
        string sb = str.substr(16, 8);
        int r = stoi(sr, 0, 2);
        int g = stoi(sg, 0, 2);
        int b = stoi(sb, 0, 2);
        vector<int> a = { calc(r, g, b), calc(M - r, M - g, M - b),
            calc(M - r, g, b), calc(r, M - g, b), calc(r, g, M - b)
        };
        int m = *min_element(a.begin(), a.end());
        if (count(a.begin(), a.end(), m) > 1) {
            res.push_back("Ambiguous");
            continue;
        }
        int i = 0;
        while (a[i] > m) i++;
        res.push_back(ans[i]);
    }
    return res;
}

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
