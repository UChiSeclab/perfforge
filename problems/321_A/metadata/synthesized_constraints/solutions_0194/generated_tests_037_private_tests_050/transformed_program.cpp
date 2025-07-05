#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int ci[256];

void check_repetitive_movement_invariant(int x, int y) {
    if (x == 0 && y == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - repetitive movement with no net change!" << endl;
        abort();
    }
}

void check_ineffective_position_invariant(int x, int y, int a, int b) {
    if ((a != 0 || b != 0) && (x == 0 && y == 0)) {
        cerr << "Warning: Performance bottleneck condition triggered - ineffective position reach!" << endl;
        abort();
    }
}

void check_unbounded_iteration_invariant(int x, int y, int a, int b) {
    if (abs(a) > abs(x) || abs(b) > abs(y)) {
        cerr << "Warning: Performance bottleneck condition triggered - unbounded iteration in simulation!" << endl;
        abort();
    }
}

int main() {
    ci['U'] = 3;
    ci['D'] = 1;
    ci['L'] = 0;
    ci['R'] = 2;
    int n, x, y, a, b;
    string s;
    cin >> a >> b >> s;
    
    n = s.size();
    x = y = 0;
    for (int i = 0; i < n; i++) {
        x += dx[ci[s[i]]];
        y += dy[ci[s[i]]];
    }
    
    // Check for performance invariants
    check_repetitive_movement_invariant(x, y);
    check_ineffective_position_invariant(x, y, a, b);
    check_unbounded_iteration_invariant(x, y, a, b);
    
    x = y = 0;
    for (int i = 0; i < n; i++) {
        x += dx[ci[s[i]]];
        y += dy[ci[s[i]]];
        if (a == x && b == y) {
            puts("Yes");
            return 0;
        }
    }
    if (x == 0 && y == 0) {
        puts("No");
        return 0;
    }
    
    int t = 0;
    if (x > 0) t = max(t, (a - 200) / x);
    if (x < 0) t = max(t, (a + 200) / x);
    if (y > 0) t = max(t, (b - 200) / y);
    if (y < 0) t = max(t, (b + 200) / y);
    
    x *= t;
    y *= t;
    
    for (int j = 0; j < 10000; j++) {
        for (int i = 0; i < n; i++) {
            x += dx[ci[s[i]]];
            y += dy[ci[s[i]]];
            if (a == x && b == y) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}