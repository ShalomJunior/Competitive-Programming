#include<bits/stdc++.h>
using namespace std;

string enc(string s, int c) {
    int len = s.length();
    if (len == 0) {
        return "";
    }
    int r = (len + c - 1) / c;
    while (len < r * c) {
        s += '=';
        len++;
    }
    vector<vector<char>> a(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = s[i * c + j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    string ans;
    vector<vector<bool>> vis(r, vector<bool>(c));
    int i = 0;
    int j = 0;
    int k = 0;
    int cnt = len;
    while (cnt) {
        i = k;
        j = k;
        while (j < c && !vis[i][j]) {
            ans += a[i][j];
            vis[i][j] = true;
            j++;
            cnt--;
        }
        j--;
        i++;
        while (i < r && !vis[i][j]) {
            ans += a[i][j];
            vis[i][j] = true;
            i++;
            cnt--;
        }
        i--;
        j--;
        while (j >= 0 && !vis[i][j]) {
            ans += a[i][j];
            vis[i][j] = true;
            j--;
            cnt--;
        }
        i--;
        j++;
        while (i >= 0 && !vis[i][j]) {
            ans += a[i][j];
            vis[i][j] = true;
            i--;
            cnt--;
        }
        k++;
    }
    return ans;
}

string dec(string s, int c) {
    int len = s.length();
    if (len == 0) {
        return "";
    }
    if (len % c) {
        cout << "You give me wrong input" << endl;
        return "";
    }
    int r = len / c;
    string ans;
    vector<vector<char>> a(r, vector<char>(c));
    vector<vector<bool>> vis(r, vector<bool>(c));
    int i = 0;
    int j = 0;
    int id = 0;
    int k = 0;
    int cnt = len;
    while (cnt) {
        i = k;
        j = k;
        while (j < c && !vis[i][j]) {
            a[i][j] = s[id++];
            vis[i][j] = true;
            j++;
            cnt--;
        }
        j--;
        i++;
        while (i < r && !vis[i][j]) {
            a[i][j] = s[id++];
            vis[i][j] = true;
            i++;
            cnt--;
        }
        i--;
        j--;
        while (j >= 0 && !vis[i][j]) {
            a[i][j] = s[id++];
            vis[i][j] = true;
            j--;
            cnt--;
        }
        i--;
        j++;
        while (i >= 0 && !vis[i][j]) {
            a[i][j] = s[id++];
            vis[i][j] = true;
            i--;
            cnt--;
        }
        k++;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans += a[i][j];
        }
    }
    while (!ans.empty() && ans.back() == '=') ans.pop_back();
    return ans;
}
void solve() {
    int c;
    string s;
    cin >> s >> c;
    cout << enc(s, c) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << "s = " << s << endl;
    cout << "Enter t : ";
    int t;
    cin >> t;
    cout << "t = " << t << endl;
    solve();
}
