#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    int prefCount;
    int wordCount;
    TrieNode() : isEndOfWord(false), prefCount(0), wordCount(0) {
        children.assign(15, nullptr);
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - '0';

            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->prefCount++;
        }
        curr->isEndOfWord = true;
        curr->wordCount++;
    }

    int count(const string& word) const {
        TrieNode* curr = root;
        int ans = 0;
        for (char c : word) {
            int index = c - '0';
            if (!curr->children[index]) {
                break;
            }
            ans++;
            curr = curr->children[index];
        }
        return ans;
    }
};

string to_string(vector<int>& a) {
    string ans;
    for (auto& c : a) ans += to_string(c);
    cerr << "ans " << ans << endl;
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            --a[i][j];
        }
    }

    Trie T;
    for (auto& p : a) T.insert(to_string(p));
    for (int i = 0; i < n; i++) {
        vector<int> q(m);
        for (int j = 0; j < m; j++) {
            q[a[i][j]] = j;
        }
        // for (auto& c : q) cerr << c << " -> ";
        // cerr << endl;
        cout << T.count(to_string(q)) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}