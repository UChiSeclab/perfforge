#include <bits/stdc++.h>
using namespace std;

// Checker for high iteration count due to zero net displacement per cycle
void check_high_iteration_invariant(int dx, int dy) {
    if (dx == 0 && dy == 0) {
        cerr << "Warning: High iteration invariant triggered - net displacement per cycle is zero!" << endl;
        abort();
    }
}

// Checker for inefficient movement pattern
void check_inefficient_movement_invariant(int netDx, int netDy) {
    if (netDx == 0 && netDy == 0) {
        cerr << "Warning: Inefficient movement invariant triggered - minimal or zero net displacement per cycle!" << endl;
        abort();
    }
}

// Checker for large target coordinates
void check_large_target_invariant(int a, int b) {
    if (abs(a) > 1e9 || abs(b) > 1e9) {
        cerr << "Warning: Large target invariant triggered - target coordinates are very large!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    string s;
    cin >> a >> b >> s;

    check_large_target_invariant(a, b);  // Check if target coordinates are unreasonably large

    int dx = 0, dy = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'R') {
            dx++;
        } else if (s[i] == 'L') {
            dx--;
        } else if (s[i] == 'U') {
            dy++;
        } else if (s[i] == 'D') {
            dy--;
        }
    }

    check_high_iteration_invariant(dx, dy);  // Check for zero net displacement

    int k = 0;
    if (dx != 0 && dy != 0) {
        int n1 = a / dx;
        int n2 = b / dy;
        k = max(n1, n2);
    }
    if (dx == 0 && dy != 0) {
        k = max(0, b / dy);
    }
    if (dy == 0 && dx != 0) {
        k = max(a / dx, 0);
    }
    k = max(0, k - 21000);
    a -= k * dx;
    b -= k * dy;

    dx = 0, dy = 0;
    for (int i = 1; i <= 32000; i++) {
        for (int i = 0; i < (int)s.length(); i++) {
            if (dx == a && dy == b) {
                cout << "Yes" << "\n";
                return 0;
            }
            if (s[i] == 'R') {
                dx++;
            } else if (s[i] == 'L') {
                dx--;
            } else if (s[i] == 'U') {
                dy++;
            } else if (s[i] == 'D') {
                dy--;
            }
            if (dx == a && dy == b) {
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }
    cout << "No" << "\n";
}