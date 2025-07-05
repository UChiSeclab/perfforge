#include <bits/stdc++.h>
using namespace std;

// Checker for invariant: Small target values with large iterations
void check_small_values_invariant(int num, int j, int z) {
    if (num <= 7 && j == 100 && z == 100) {
        cerr << "Warning: Performance bottleneck condition triggered - Small target value with full iterations!" << endl;
        abort();
    }
}

// Checker for invariant: High test case number with inefficient loops
void check_high_test_cases_invariant(int n, int unsuccessfulIterations) {
    if (n > 40 && unsuccessfulIterations > 4000) {
        cerr << "Warning: Performance bottleneck condition triggered - High number of test cases with inefficient loops!" << endl;
        abort();
    }
}

// Checker for invariant: Loop boundary conditions
void check_loop_boundary_invariant(int j, int z) {
    if (j == 100 && z == 100) {
        cerr << "Warning: Performance bottleneck condition triggered - Loop reached maximum boundary without finding a solution!" << endl;
        abort();
    }
}

int main() {
    int n, x;
    cin >> n;
    vector<int> X(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        X[i] = x;
    }
    bool flag = false;
    
    int unsuccessfulIterations = 0; // Track unsuccessful iterations

    for (int i = 0; i < n; i++) {
        flag = false;
        int num = X[i];
        for (int j = 0; j <= 100; j++) {
            for (int z = 0; z <= 100; z++) {
                if ((j * 3 + z * 7) == num) {
                    flag = true;
                    break;
                }
                // Increment unsuccessful iterations
                unsuccessfulIterations++;
                // Check loop boundary invariant
                check_loop_boundary_invariant(j, z);
            }
            if (flag) {
                break;
            }
        }
        // Check small values invariant
        check_small_values_invariant(num, 100, 100);

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    // Check high test cases invariant
    check_high_test_cases_invariant(n, unsuccessfulIterations);
    
    return 0;
}