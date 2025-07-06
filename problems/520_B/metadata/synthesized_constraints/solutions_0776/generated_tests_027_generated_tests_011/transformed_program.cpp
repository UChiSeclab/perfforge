#include <bits/stdc++.h>
using namespace std;

// Checkers for performance invariants
void check_inefficient_exploration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient state exploration!" << endl;
        abort();
    }
}

void check_excessive_iterations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive loop iterations!" << endl;
        abort();
    }
}

void check_state_transition_overhead(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to state transition overhead!" << endl;
        abort();
    }
}

bool vis[2][10000 + 10];

int main(void) {
    int n, m;
    cin >> n >> m;

    // Invariant check: Inefficient State Exploration
    check_inefficient_exploration(n > m * 2);

    // Invariant check: Excessive Iterations
    check_excessive_iterations(n > 9000 && m < 100);

    // Invariant check: State Transition Overhead
    check_state_transition_overhead(n > 8000 && (n - m) > 5000);

    vis[0][n] = true;
    for (int ans = 0;; ans++) {
        int nop = ans % 2;
        int nxp = nop ^ 1;
        if (vis[nop][m]) {
            cout << ans;
            return 0;
        }
        for (int i = 1; i <= 10000; i++) {
            if (vis[nop][i]) {
                vis[nxp][i] = true;
                if (i > 1) vis[nxp][i - 1] = true;
                if (i * 2 <= 10000) vis[nxp][i * 2] = true;
            }
        }
    }
    return 0;
}