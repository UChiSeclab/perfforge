#include <bits/stdc++.h>
using namespace std;

struct thing {
    int x;
    int y;
    bool operator<(const thing &th) const {
        if (y < th.y) return true;
        if (y == th.y && x < th.x) return true;
        return false;
    }
} m[5], n[5];

// Checker for exhaustive search
void check_exhaustive_search(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - exhaustive search executed!" << endl;
        abort();
    }
}

// Checker for high iteration count
void check_high_iteration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count in okm function!" << endl;
        abort();
    }
}

bool okn(int x, int y) {
    if (x >= m[1].x)
        if (y >= m[1].y)
            if (x <= m[4].x)
                if (y <= m[4].y) return true;
    return false;
}

bool okm(int x, int y) {
    if (x + y >= n[1].x + n[1].y)
        if (x + y <= n[4].x + n[4].y)
            if (y - x >= n[1].y - n[1].x)
                if (y - x <= n[4].y - n[4].x) return true;
    return false;
}

int main() {
    for (int i = 1; i <= 4; i++) cin >> m[i].x >> m[i].y;
    for (int i = 1; i <= 4; i++) cin >> n[i].x >> n[i].y;
    sort(m + 1, m + 5);
    sort(n + 1, n + 5);

    // Check if neither square's vertices are in the other's bounds
    bool square_intersection = false;
    for (int i = 1; i <= 4; i++) {
        if (okn(n[i].x, n[i].y)) {
            square_intersection = true;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        if (okm(m[i].x, m[i].y)) {
            square_intersection = true;
            break;
        }
    }
    check_exhaustive_search(!square_intersection);

    // Check for high iteration in brute-force search
    bool high_iteration = false;
    for (int i = -100; i <= 100; i++) {
        for (int j = -100; j <= 100; j++) {
            if (okm(i, j) && okn(i, j)) {
                cout << "YES";
                return 0;
            }
        }
    }
    check_high_iteration(high_iteration);

    cout << "NO";
    return 0;
}