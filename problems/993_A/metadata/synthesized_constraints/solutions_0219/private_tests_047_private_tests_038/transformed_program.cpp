#include <bits/stdc++.h>
using namespace std;
const int MAX = 400;
pair<int, int> a[5], b[5];

void norm(pair<int, int> &p) {
    p.first *= 4;
    p.second *= 4;
}

bool in_range(int val, int lo, int hi) { 
    return val >= lo && val <= hi; 
}

bool in_first(int x, int y) {
    int x1 = MAX, x2 = -MAX;
    int y1 = MAX, y2 = -MAX;
    for (int i = 0; i < 4; i++) {
        x1 = min(x1, a[i].first);
        x2 = max(x2, a[i].first);
        y1 = min(y1, a[i].second);
        y2 = max(y2, a[i].second);
    }
    return in_range(x, x1, x2) && in_range(y, y1, y2);
}

bool in_second(int x, int y) {
    int x1 = 2 * MAX, x2 = -2 * MAX;
    int y1 = 2 * MAX, y2 = -2 * MAX;
    for (int i = 0; i < 4; i++) {
        x1 = min(x1, b[i].first - b[i].second);
        x2 = max(x2, b[i].first - b[i].second);
        y1 = min(y1, b[i].first + b[i].second);
        y2 = max(y2, b[i].first + b[i].second);
    }
    return in_range(x - y, x1, x2) && in_range(x + y, y1, y2);
}

// Performance checker functions
void check_grid_exhaustion(int maxX, int maxY) {
    if (maxX > 400 || maxY > 400) {
        cerr << "Warning: Performance bottleneck condition triggered - grid too large!" << endl;
        abort();
    }
}

void check_inefficient_boundary(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient boundary checks!" << endl;
        abort();
    }
}

void check_loop_optimization(int x1, int x2, int y1, int y2) {
    if ((x2 - x1) > 200 || (y2 - y1) > 200) {
        cerr << "Warning: Performance bottleneck condition triggered - large bounding boxes!" << endl;
        abort();
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
        norm(a[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d%d", &b[i].first, &b[i].second);
        norm(b[i]);
    }
    
    // Calculate bounding box dimensions for initial check
    int x1 = MAX, x2 = -MAX;
    int y1 = MAX, y2 = -MAX;
    for (int i = 0; i < 4; i++) {
        x1 = min(x1, a[i].first);
        x2 = max(x2, a[i].first);
        y1 = min(y1, a[i].second);
        y2 = max(y2, a[i].second);
    }
    check_loop_optimization(x1, x2, y1, y2);

    // Before the nested loops to check grid exhaustion
    check_grid_exhaustion(MAX, MAX);

    for (int i = -MAX; i <= MAX; i++)
        for (int j = -MAX; j <= MAX; j++)
            if (in_first(i, j) && in_second(i, j)) {
                puts("yes");
                return 0;
            }

    puts("no");
    return 0;
}