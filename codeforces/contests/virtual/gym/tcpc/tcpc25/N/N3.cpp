#include <bits/stdc++.h>
using namespace std;

struct NodeY {
    int cnt;
    NodeY* left, * right;
    NodeY() : cnt(0), left(nullptr), right(nullptr) {}
};

struct NodeX {
    NodeY* treeY;
    NodeX* left, * right;
    NodeX() : treeY(nullptr), left(nullptr), right(nullptr) {}
};

// Update the y-dimension segment tree at compressed coordinate 'pos'
void updateY(NodeY*& node, int L, int R, int pos, int val) {
    if (!node) node = new NodeY();
    node->cnt += val;
    if (L == R) return;
    int mid = (L + R) / 2;
    if (pos <= mid)
        updateY(node->left, L, mid, pos, val);
    else
        updateY(node->right, mid + 1, R, pos, val);
}

// Query the y-dimension segment tree in range [ql, qr]
int queryY(NodeY* node, int L, int R, int ql, int qr) {
    if (!node) return 0;
    if (ql <= L && R <= qr) return node->cnt;
    int mid = (L + R) / 2;
    int ans = 0;
    if (ql <= mid)
        ans += queryY(node->left, L, mid, ql, qr);
    if (qr > mid)
        ans += queryY(node->right, mid + 1, R, ql, qr);
    return ans;
}

// Update the x-dimension tree at compressed x-index 'x', updating its associated y-tree at 'y'
void updateX(NodeX*& node, int L, int R, int x, int y, int val, int compYSize) {
    if (!node) node = new NodeX();
    updateY(node->treeY, 0, compYSize - 1, y, val);
    if (L == R) return;
    int mid = (L + R) / 2;
    if (x <= mid)
        updateX(node->left, L, mid, x, y, val, compYSize);
    else
        updateX(node->right, mid + 1, R, x, y, val, compYSize);
}

// Query the x-dimension tree for points with x in [ql, qr] and y in [y1, y2]
int queryX(NodeX* node, int L, int R, int ql, int qr, int y1, int y2, int compYSize) {
    if (!node) return 0;
    if (ql <= L && R <= qr)
        return queryY(node->treeY, 0, compYSize - 1, y1, y2);
    int mid = (L + R) / 2;
    int ans = 0;
    if (ql <= mid)
        ans += queryX(node->left, L, mid, ql, qr, y1, y2, compYSize);
    if (qr > mid)
        ans += queryX(node->right, mid + 1, R, ql, qr, y1, y2, compYSize);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    vector<int> xs, ys;
    for (int i = 0; i < n; i++) {
        int _, x, y;
        cin >> _ >> _ >> x >> y;
        points[i] = { x, y };
        xs.push_back(x);
        ys.push_back(y);
    }

    // Coordinate compression
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int compX = xs.size(), compY = ys.size();

    NodeX* root = nullptr;
    // Insert each point using its compressed coordinates
    for (auto& p : points) {
        int cx = int(lower_bound(xs.begin(), xs.end(), p.first) - xs.begin());
        int cy = int(lower_bound(ys.begin(), ys.end(), p.second) - ys.begin());
        updateX(root, 0, compX - 1, cx, cy, 1, compY);
    }
    int q;
    cin >> q;
    while (q--) {
        int x1 = 0, y1 = 0, x2, y2;
        cin >> x2 >> y2;
        // We assume the query rectangle is inclusive.
        // Map x1 to the first compressed index >= x1,
        // and x2 to the last compressed index <= x2.
        int cx1 = int(lower_bound(xs.begin(), xs.end(), x1) - xs.begin());
        int cx2 = int(upper_bound(xs.begin(), xs.end(), x2) - xs.begin()) - 1;
        int cy1 = int(lower_bound(ys.begin(), ys.end(), y1) - ys.begin());
        int cy2 = int(upper_bound(ys.begin(), ys.end(), y2) - ys.begin()) - 1;
        if (cx1 > cx2 || cy1 > cy2)
            cout << 0 << "\n";
        else {
            int ans = queryX(root, 0, compX - 1, cx1, cx2, cy1, cy2, compY);
            cout << ans << "\n";
        }
    }
    return 0;
}
