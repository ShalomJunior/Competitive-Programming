#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Point {
    int x, y, price;
    Point(int x, int y, int price) : x(x), y(y), price(price) {}
};

vector<int> compress(vector<int>& coords) {
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    return coords;
}

int getIndex(const vector<int>& coords, int val) {
    return lower_bound(coords.begin(), coords.end(), val) - coords.begin();
}

struct MergeSortTree {
    struct Node {
        vector<int> x_orders;
        vector<int> prices;
        vector<vector<int>> rmq;

        void build_rmq() {
            int n = prices.size();
            if (n == 0) return;
            int logn = 32 - __builtin_clz(n);
            rmq.assign(logn, vector<int>(n));
            rmq[0] = prices;
            for (int k = 1; k < logn; ++k) {
                for (int i = 0; i + (1 << k) <= n; ++i) {
                    rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        int query(int l, int r) {
            if (l > r || x_orders.empty()) return INT_MAX;
            int left = lower_bound(x_orders.begin(), x_orders.end(), l) - x_orders.begin();
            int right = upper_bound(x_orders.begin(), x_orders.end(), r) - x_orders.begin() - 1;
            if (left > right) return INT_MAX;
            int k = 31 - __builtin_clz(right - left + 1);
            return min(rmq[k][left], rmq[k][right - (1 << k) + 1]);
        }
    };

    int n;
    vector<Node> tree;
    vector<int> y_coords;

    MergeSortTree(const vector<int>& y_coords) : y_coords(y_coords) {
        n = y_coords.size();
        tree.resize(4 * n);
    }

    void build(int node, int l, int r, const vector<Point>& points) {
        if (l == r) {
            for (const Point& p : points) {
                if (p.y == y_coords[l]) {
                    tree[node].x_orders.push_back(p.x);
                    tree[node].prices.push_back(p.price);
                }
            }
            tree[node].build_rmq();
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, points);
        build(2 * node + 2, mid + 1, r, points);
        auto& left = tree[2 * node + 1].x_orders;
        auto& right = tree[2 * node + 2].x_orders;
        tree[node].x_orders.resize(left.size() + right.size());
        merge(left.begin(), left.end(), right.begin(), right.end(), tree[node].x_orders.begin());
        tree[node].prices.resize(tree[node].x_orders.size());
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                tree[node].prices[k++] = tree[2 * node + 1].prices[i++];
            }
            else {
                tree[node].prices[k++] = tree[2 * node + 2].prices[j++];
            }
        }
        while (i < left.size()) tree[node].prices[k++] = tree[2 * node + 1].prices[i++];
        while (j < right.size()) tree[node].prices[k++] = tree[2 * node + 2].prices[j++];
        tree[node].build_rmq();
    }

    int query(int node, int l, int r, int y_l, int y_r, int x_l, int x_r) {
        if (y_coords[r] < y_l || y_coords[l] > y_r) return INT_MAX;
        if (y_l <= y_coords[l] && y_coords[r] <= y_r) {
            return tree[node].query(x_l, x_r);
        }
        int mid = (l + r) / 2;
        return min(query(2 * node + 1, l, mid, y_l, y_r, x_l, x_r),
            query(2 * node + 2, mid + 1, r, y_l, y_r, x_l, x_r));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points;
    vector<int> all_x, all_y;
    for (int i = 0; i < n; ++i) {
        int x, y, p;
        cin >> x >> y >> p;
        points.emplace_back(x, y, p);
        all_x.push_back(x);
        all_y.push_back(y);
    }
    int q;
    cin >> q;
    vector<tuple<int, int, int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries[i] = { x1, y1, x2, y2 };
        all_x.push_back(x1);
        all_x.push_back(x2);
        all_y.push_back(y1);
        all_y.push_back(y2);
    }

    // Compress coordinates
    compress(all_x);
    compress(all_y);

    // Assign compressed x and y to points
    vector<Point> sorted_points;
    for (auto& p : points) {
        int cx = getIndex(all_x, p.x);
        int cy = getIndex(all_y, p.y);
        sorted_points.emplace_back(cx, cy, p.price);
    }

    // Sort points by x
    sort(sorted_points.begin(), sorted_points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
        });

    // Assign x_order (sorted by x)
    for (int i = 0; i < sorted_points.size(); ++i) {
        sorted_points[i].x = i;
    }

    // Compress y_coords for MergeSortTree
    vector<int> y_coords = all_y;
    compress(y_coords);

    // Build MergeSortTree
    MergeSortTree mst(y_coords);
    mst.build(0, 0, y_coords.size() - 1, sorted_points);

    // Process queries
    for (auto& [x1, y1, x2, y2] : queries) {
        int cx1 = getIndex(all_x, x1);
        int cx2 = getIndex(all_x, x2);
        if (all_x[cx1] < x1) ++cx1;
        if (cx1 >= all_x.size()) {
            cout << "-1\n";
            continue;
        }
        cx2 = upper_bound(all_x.begin(), all_x.end(), x2) - all_x.begin() - 1;
        if (cx2 < 0) {
            cout << "-1\n";
            continue;
        }

        int cy1 = getIndex(all_y, y1);
        int cy2 = getIndex(all_y, y2);
        if (all_y[cy2] > y2) --cy2;
        if (cy1 > cy2) {
            cout << "-1\n";
            continue;
        }

        int min_price = mst.query(0, 0, y_coords.size() - 1, cy1, cy2, cx1, cx2);
        cout << (min_price == INT_MAX ? -1 : min_price) << '\n';
    }

    return 0;
}