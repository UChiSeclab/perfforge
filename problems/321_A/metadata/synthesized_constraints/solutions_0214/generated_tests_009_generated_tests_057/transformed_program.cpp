#include <bits/stdc++.h>
using namespace std;

// Checker functions (as defined above)
void check_long_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient long loop execution!" << endl;
        abort();
    }
}

void check_movement_step_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to inadequate movement step size!" << endl;
        abort();
    }
}

void check_repeated_set_operations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to repeated set operations!" << endl;
        abort();
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int dx[256] = {};
    int dy[256] = {};
    dx['L'] = -1;
    dx['R'] = +1;
    dy['D'] = -1;
    dy['U'] = +1;
    int mx = 0, my = 0;
    int l = 0, r = 0;
    set<pair<int, int>> st;
    st.insert(make_pair(0, 0));
    for (int i = 0; i < (int)(s.size()); ++i) {
        mx += dx[s[i]];
        my += dy[s[i]];
        l = min(l, mx);
        r = max(r, mx);
        st.insert(make_pair(mx, my));
    }
    
    // Checkers for Invariants
    // Check if a and b are unreachable with the initial moves
    check_long_loop_invariant(!st.count(make_pair(a, b)) && s.size() == 100);
    
    // Check if the net movement in x or y is inadequate
    int netMovementX = r - l;
    int netMovementY = my;
    check_movement_step_invariant(netMovementX == 0 && a != 0 || netMovementY == 0 && b != 0);
    
    long long move = 0;
    long long x, y;
    if (st.count(make_pair(a, b))) goto check;
    if (mx != 0 && a / mx > 0) {
        move = max(a / mx - 5000, 0);
    } else if (my != 0 && b / my > 0) {
        move = max(b / my - 5000, 0);
    }
    x = mx * move, y = my * move;
    
    // Check if the set is overutilized with repeating operations
    check_repeated_set_operations_invariant(move == 0 && s.size() == 100);
    
    for (int j = 0; j < 10000; ++j) {
        for (int i = 0; i < (int)(s.size()); ++i) {
            x += dx[s[i]];
            y += dy[s[i]];
            st.insert(make_pair(x, y));
        }
    }
check:
    if (st.count(make_pair(a, b)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}