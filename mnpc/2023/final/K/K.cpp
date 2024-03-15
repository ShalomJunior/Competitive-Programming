#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    int prefCount;
    int wordCount;
    TrieNode() : isEndOfWord(false), prefCount(0), wordCount(0), children(2, nullptr) {}
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
            int i = (c == 'L') ? 0 : 1;
            if (!curr->children[i]) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
            curr->prefCount++;
        }
        curr->isEndOfWord = true;
        curr->wordCount++;
    }
    int count(const string& word) const {
        TrieNode* curr = root;
        for (char c : word) {
            int i = (c == 'L') ? 0 : 1;
            if (!curr->children[i]) {
                return 0;
            }
            curr = curr->children[i];
        }
        return curr->wordCount;
    }
    vector<int> countStartWith(const string& prefix) {
        int n = prefix.length();
        vector<int> result(n + 1);
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            char c = prefix[i];
            int j = (c == 'L') ? 0 : 1;
            if (!curr->children[j]) {
                result.push_back(0);
                return result;
            }
            curr = curr->children[j];
            result[i + 1] = curr->prefCount;
        }
        return result;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Trie trie;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        trie.insert(s);
    }
    while (q--) {
        string s;
        cin >> s;
        cout << trie.countStartWith(s)[s.length()] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}