#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int prefCount;
    int wordCount;
    int cnt;
    string ans;
    TrieNode() :isEndOfWord(false), prefCount(0), wordCount(0), cnt(0), ans("{") {}
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
        vector<TrieNode*> order;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            order.push_back(curr);
            curr->prefCount++;
        }
        curr->isEndOfWord = true;
        curr->wordCount++;
        string new_word = word;
        int new_count = curr->wordCount;
        for (int i = order.size() - 1; i >= 0; i--) {
            auto ths = order[i];
            if (ths->cnt > new_count) {
                new_word = ths->ans;
                new_count = ths->cnt;
            }
            else if (ths->cnt == new_count) {
                new_word = min(ths->ans, new_word);
                new_count = ths->cnt;
            }
            else {
            }
            ths->cnt = new_count;
            ths->ans = new_word;
        }
    }
    string search(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                assert(false);
            }
            curr = curr->children[c];
        }
        return curr->ans;
    }
};

void solve() {
    int n; cin >> n;
    Trie trie;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        trie.insert(s);
    }
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        cout << trie.search(s) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}