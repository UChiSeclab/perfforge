#include <bits/stdc++.h>
using namespace std;
long long int i, j, n, t, m, a, b, cof, k, arr[1000000], dx, dy, p, xx, yy;
string s, s2;

// Checker functions for performance bottlenecks

// Check for inefficient net movement
void check_inefficient_net_movement(long long dx, long long dy) {
    if (dx == 0 && dy == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient net movement (dx and dy are zero)!" << endl;
        abort();
    }
}

// Check for large loop iterations due to extreme values of k or p
void check_large_loop_iterations(long long k, long long p, long long m) {
    if (m >= 1000 && (k == 1000000000000 || p == 1000000000000)) {
        cerr << "Warning: Performance bottleneck condition triggered - large loop iterations due to extreme k or p values!" << endl;
        abort();
    }
}

int main() {
    cin >> a >> b;
    cin >> s;
    n = s.length();
    dx = dy = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == 'U') dy++;
        if (s[i] == 'D') dy--;
        if (s[i] == 'R') dx++;
        if (s[i] == 'L') dx--;
    }

    // Check the net movement immediately after computing dx and dy
    check_inefficient_net_movement(dx, dy);

    if (dx != 0)
        k = a / dx;
    else
        k = 1000000000000;
    if (k < 0) k = 0;
    k++;
    if (dy != 0)
        p = b / dy;
    else
        p = 1000000000000;
    if (p < 0) p = 0;
    p++;
    m = min(k, p);
    if (m < 1000) m = 1000;

    // Check for potential large loop iterations
    check_large_loop_iterations(k, p, m);

    xx = dx * m;
    yy = dy * m;
    for (i = 0; i < 1000; i++)
        for (j = n - 1; j >= 0; j--) {
            if ((xx == a) && (yy == b)) {
                cout << "Yes";
                return 0;
            }
            if (s[j] == 'U') yy--;
            if (s[j] == 'D') yy++;
            if (s[j] == 'R') xx--;
            if (s[j] == 'L') xx++;
            if ((xx == a) && (yy == b)) {
                cout << "Yes";
                return 0;
            }
        }
    cout << "No";
}