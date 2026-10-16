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

    void remove(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                assert(false);
            }
            curr = curr->children[index];
            curr->prefCount--;
        }
        curr->isEndOfWord = false;
        curr->wordCount--;
    }

    int count(const string& word, bool end = true) const {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                return 0;
            }
            curr = curr->children[index];
        }
        return end ? curr->isEndOfWord : curr->prefCount;
    }
};

void solve() {
    int q;
    cin >> q;
    Trie T;
    while (q--) {
        string t, p;
        cin >> t >> p;
        if (t == "INSERT") {
            if (T.count(p) == 0)
                T.insert(p);
        }
        else if (t == "DELETE") {
            if (T.count(p) == 1) {
                T.remove(p);
                cout << "DELETED";
            }
            else {
                cout << "NOT FOUND";
            }
            cout << endl;
        }
        else if (t == "COUNT") {
            cout << T.count(p, false) << endl;
        }
        else {
            assert(false);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}