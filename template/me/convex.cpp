#include <iostream>
#include <vector>
#include <algorithm>

// A struct to represent a point in 2D space.
// We use long long for coordinates to avoid overflow, which is common in competitive programming.
struct Point {
    long long x, y;
};

// Custom comparison function to sort points lexicographically.
bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

// Function to calculate the cross product of three points (p, q, r).
// Returns a positive value for a left turn, negative for a right turn,
// and zero for collinear points.
long long cross_product(const Point& p, const Point& q, const Point& r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

// Main function to compute the convex hull using the Monotone Chain algorithm.
std::vector<Point> convex_hull(std::vector<Point>& points) {
    int n = points.size();
    if (n <= 2) {
        return points;
    }

    // Sort the points lexicographically to start.
    std::sort(points.begin(), points.end(), comparePoints);

    std::vector<Point> hull;

    // Build the lower hull.
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // Build the upper hull.
    int upper_hull_start = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > upper_hull_start && cross_product(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // The last point added will be the same as the first. Remove it to avoid duplicates.
    hull.pop_back();

    return hull;
}
