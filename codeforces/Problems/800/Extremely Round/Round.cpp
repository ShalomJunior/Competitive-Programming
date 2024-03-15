#include<bits/stdc++.h>

using namespace std;

const int N = 1e7;

vector<int> zero(N);

int cnt(int i) {
    int ans = 0;
    string str = to_string(i);
    for (auto& c : str) {
        if (c != '0') ans++;
    }
    return ans;
}
void compute() {
    for (int i = 1; i < N; i++)
        zero[i] = zero[i - 1] + (cnt(i) == 1);
}

void solve() {
    int n; cin >> n;
    cout << zero[n] << endl;
}

int main() {
    compute();
    int t; cin >> t;
    while (t--)solve();
}