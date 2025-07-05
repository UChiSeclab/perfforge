#include <bits/stdc++.h>
using namespace std;

// Function to check for nested loop performance issues
void check_nested_loop_invariant(int n) {
    if (n > 45) { // Assuming n is close to its upper bound
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations due to large n!" << endl;
        abort();
    }
}

// Function to check for excessive combinatorial pairings
void check_combinatorial_invariant(int n) {
    if (n * (2 * n - 1) > 1000) { // Evaluating (2n choose 2) for a substantial threshold
        cerr << "Warning: Performance bottleneck condition triggered - excessive combinatorial pairings!" << endl;
        abort();
    }
}

// Function to check for redundant calculations
void check_redundant_calculation_invariant(int n) {
    if (n > 40) { // Assuming a threshold beyond which redundant calculations become costly
        cerr << "Warning: Performance bottleneck condition triggered - redundant sum calculations!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c, n, i, s1 = 100000, sum = 0;
    cin >> n;
    
    // Initial checks after reading input size n
    check_nested_loop_invariant(n);
    check_combinatorial_invariant(n);
    check_redundant_calculation_invariant(n);

    int a[2 * n];
    for (i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(a, a + 2 * n);

    for (int j = 0; j < 2 * n - 1; j++) {
        for (int k = j + 1; k < 2 * n; k++) {
            sum = 0;
            c = 1;
            for (i = 0; i < 2 * n; i++) {
                if (i != k && i != j) {
                    sum += (pow(-1, c) * a[i]);
                    c++;
                }
            }
            s1 = min(s1, sum);
        }
    }

    cout << s1;
    return 0;
}