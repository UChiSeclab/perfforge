#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ld = long double;
const ld PI = acos(-1.0);

struct pnt {
    int x, y;
    bool read() {
        return cin >> x >> y;
    }
    int operator*(const pnt& p) const { return x * p.x + y * p.y; }
    int operator%(const pnt& p) const { return x * p.y - y * p.x; }
    pnt operator-(const pnt& p) const { return pnt{x - p.x, y - p.y}; }
    bool operator==(const pnt& p) const { return x == p.x && y == p.y; }
};

struct sq {
    vector<pnt> ps;
    bool read() {
        ps.resize(4);
        for (auto& p : ps) {
            if (!p.read()) {
                return 0;
            }
        }
        return 1;
    }
    bool inside(const pnt& p) const {
        ld sum = 0;
        for (int i = 0; i < int(ps.size()); ++i) {
            if (ps[i] == p) {
                return 1;
            }
            auto p1 = ps[i] - p;
            auto p2 = ps[(i + 1) % ps.size()] - p;
            if ((p1 % p2) == 0 && (p1 * p2) <= 0) {
                return 1;
            }
            ld ang = atan2(p1 % p2, p1 * p2);
            sum += ang;
        }
        return fabs(sum) > PI;
    }
};

sq s1, s2;

// Checkers for performance bottlenecks
void check_large_search_space(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large search space!" << endl;
        abort();
    }
}

void check_exhaustive_point_checking(bool condition, int totalPointsChecked) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to exhaustive point checking!" << endl;
        cerr << "Total points checked: " << totalPointsChecked << endl;
        abort();
    }
}

void check_costly_geometric_calculations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to costly geometric calculations!" << endl;
        abort();
    }
}

bool solve() {
    int totalPointsChecked = 0;
    for (int x = -100; x <= 100; ++x) {
        for (int y = -100; y <= 100; ++y) {
            ++totalPointsChecked;
            if (s1.inside(pnt{x, y}) && s2.inside(pnt{x, y})) {
                return 1;
            }
        }
    }
    // Check for potential bottlenecks after the heavy loop
    check_exhaustive_point_checking(totalPointsChecked > 10000, totalPointsChecked); // Arbitrary threshold
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    while (s1.read() && s2.read()) {
        check_large_search_space(true);  // Condition is always true due to the fixed grid size
        check_costly_geometric_calculations(true);  // Condition is considered true given the repetitive calculations
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}