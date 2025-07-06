#include <bits/stdc++.h>
using namespace std;

// Function to check nested loop inefficiency
void check_nested_loops_invariant(int n, int currentTestCase) {
    if (n > 50 && currentTestCase > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop iterations due to high n and frequent small X" << endl;
        abort();
    }
}

// Function to check early loop termination
void check_early_termination_invariant(int i, int j, bool flag) {
    if (i >= 100 && j >= 100 && !flag) {
        cerr << "Warning: Performance bottleneck condition triggered - loops not terminating early on finding a solution" << endl;
        abort();
    }
}

// Function to check brute force combinations
void check_brute_force_invariant(int i, int j) {
    if (i > 90 && j > 90) {
        cerr << "Warning: Performance bottleneck condition triggered - brute-force combination checking" << endl;
        abort();
    }
}

int main() {
    int T;
    cin >> T;

    // Check for nested loop inefficiency
    check_nested_loops_invariant(T, 0);

    for (int currentTestCase = 1; currentTestCase <= T; ++currentTestCase) {
        int X;
        cin >> X;
        int flag = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                if (((3 * i) + (7 * j)) == X) {
                    flag = 1;
                    break; // Break early once a solution is found
                }
                // Check for brute force inefficiency
                check_brute_force_invariant(i, j);
            }
            if (flag) break; // Break outer loop early as well
        }
        // Check for early loop termination inefficiency
        check_early_termination_invariant(100, 100, flag);

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}