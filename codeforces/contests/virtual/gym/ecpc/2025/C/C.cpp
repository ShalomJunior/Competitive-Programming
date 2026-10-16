#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    long long val;
    long long xor_sum;
    int priority;
    int count;
    Node* l, * r;

    Node(long long v) : val(v), xor_sum(v), priority(rng()), count(1), l(nullptr), r(nullptr) {}
};

int count(Node* t) {
    return t ? t->count : 0;
}

long long xor_sum(Node* t) {
    return t ? t->xor_sum : 0LL;
}

void pull(Node* t) {
    if (t) {
        t->count = 1 + count(t->l) + count(t->r);
        t->xor_sum = t->val ^ xor_sum(t->l) ^ xor_sum(t->r);
    }
}

void split(Node* t, int k, Node*& l, Node*& r) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    int left_size = count(t->l);
    if (k <= left_size) {
        split(t->l, k, l, t->l);
        r = t;
    }
    else {
        split(t->r, k - left_size - 1, t->r, r);
        l = t;
    }
    pull(t);
}

void merge(Node*& t, Node* l, Node* r) {
    if (!l || !r) {
        t = l ? l : r;
        return;
    }
    if (l->priority > r->priority) {
        merge(l->r, l->r, r);
        t = l;
    }
    else {
        merge(r->l, l, r->l);
        t = r;
    }
    pull(t);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        long long val;
        std::cin >> val;
        merge(root, root, new Node(val));
    }

    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int inx;
            long long val;
            std::cin >> inx >> val;
            Node* l, * r;
            split(root, inx - 1, l, r);
            merge(l, l, new Node(val));
            merge(root, l, r);
        }
        else if (type == 2) {
            int inx;
            std::cin >> inx;
            Node* l, * r, * mid;
            split(root, inx, l, r);
            split(l, inx - 1, l, mid);
            merge(root, l, r);
            delete mid;
        }
        else {
            int l_idx, r_idx;
            std::cin >> l_idx >> r_idx;
            Node* left, * right, * middle;

            split(root, r_idx, left, right);
            split(left, l_idx - 1, left, middle);

            std::cout << xor_sum(middle) << "\n";

            merge(left, left, middle);
            merge(root, left, right);
        }
    }

    return 0;
}