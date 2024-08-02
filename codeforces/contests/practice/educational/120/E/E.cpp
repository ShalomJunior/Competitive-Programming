#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    int prefCount;
    int wordCount;
    TrieNode() : isEndOfWord(false), prefCount(0), wordCount(0) {
        children.assign(26, nullptr);
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
            int index = c - 'a';

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
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                return 0;
            }
            curr = curr->children[index];
        }
        return curr->wordCount;
    }

    vector<pair<int, int>> countStartWith(const string& prefix) {
        int n = prefix.length();
        vector<pair<int, int>> result;
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            char c = prefix[i];
            int index = c - 'a';
            if (!curr->children[index]) {
                result.push_back({ 0, 0 });
                return result;
            }
            curr = curr->children[index];
            if (curr->isEndOfWord) {
                result.push_back({ i + 1, curr->wordCount });
            }
        }
        return result;
    }
};

vector<int> kmp_table(string p) {
    int m = p.length();
    vector<int> ans(m);
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && p[k] != p[q]) {
            k = ans[k - 1];
        }
        if (p[q] == p[k])k++;
        ans[q] = k;
    }
    return ans;
}

vector<int> kmp(string s, string p) {
    vector<int> ans;
    int n = s.length(), m = p.length();
    auto table = kmp_table(p);
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && s[i] != p[k])k = table[k - 1];
        if (s[i] == p[k])k++;
        if (k == m) {
            ans.push_back(i - m + 1);
            k = table[k - 1];
        }
    }
    return ans;
}

void solve() {
    int N = 400;
    string t;
    cin >> t;
    int n = t.length();
    int m;
    cin >> m;
    Trie trie;
    vector<int> start(n + 1), end(n + 1);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int k = s.length();
        if (k > N) {
            auto res = kmp(t, s);
            for (auto& j : res) {
                start[j]++;
                end[j + k - 1]++;
            }
        }
        else {
            trie.insert(s);
        }
    }
    for (int i = 0; i < n; i++) {
        auto res = trie.countStartWith(t.substr(i, min(N, n - i)));
        for (auto& [len, cnt] : res) {
            if (len) {
                start[i] += cnt;
                end[i + len - 1] += cnt;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * end[i] * start[i + 1];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

// class TrieNode {
// public:
//     unordered_map<char, TrieNode*> children;
//     bool isEndOfWord;
//     int prefCount;
//     int wordCount;
//     TrieNode() : isEndOfWord(false), prefCount(0), wordCount(0) {}
// };

// class Trie {
// private:
//     TrieNode* root;
// public:
//     Trie() {
//         root = new TrieNode();
//     }
//     void insert(const string& word) {
//         TrieNode* curr = root;
//         for (char c : word) {
//             if (!curr->children.count(c)) {
//                 curr->children[c] = new TrieNode();
//             }
//             curr = curr->children[c];
//             curr->prefCount++;
//         }
//         curr->isEndOfWord = true;
//         curr->wordCount++;
//     }
//     int count(const string& word) const {
//         TrieNode* curr = root;
//         for (char c : word) {
//             if (!curr->children.count(c)) {
//                 return 0;
//             }
//             curr = curr->children[c];
//         }
//         return curr->wordCount;
//     }
//     auto countStartWith(const string& prefix) {
//         int n = prefix.length();
//         vector<pair<int, int>> result;
//         TrieNode* curr = root;
//         for (int i = 0; i < n; i++) {
//             char c = prefix[i];
//             if (!curr->children.count(c)) {
//                 result.push_back({ 0, 0 });
//                 return result;
//             }
//             curr = curr->children[c];
//             if (curr->isEndOfWord) {
//                 result.push_back({ i + 1, curr->wordCount });
//             }
//         }
//         return result;
//     }
// };