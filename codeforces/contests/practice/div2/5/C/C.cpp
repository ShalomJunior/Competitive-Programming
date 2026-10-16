#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    stack<int> stk;
    vector<int> first(n);
    vector<int> last(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i);
        }
        else {
            if (stk.empty()) {
                first[i] = -1;
                last[i] = -1;
            }
            else {
                int j = stk.top();
                stk.pop();
                first[i] = j;
                if (j > 0 && s[j - 1] == ')' && first[j - 1] != -1) {
                    first[i] = first[j - 1];
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')' && first[i] != -1) {
            ans.push_back(i - first[i] + 1);
        }
    }
    if (ans.empty()) {
        cout << "0 1" << endl;
    }
    else {
        int mx = *max_element(ans.begin(), ans.end());
        int cnt = count(ans.begin(), ans.end(), mx);
        cout << mx << " " << cnt << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
