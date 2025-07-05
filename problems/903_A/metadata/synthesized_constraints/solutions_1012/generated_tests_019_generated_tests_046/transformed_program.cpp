#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:5000000000")
const unsigned long long mod = 1000000007;
long long Inf = (long long)2e9;
long long LINF = (long long)1e18 + 1e17;
using namespace std;

// Checker function to detect performance bottlenecks
void check_unsuccessful_combinations(int x) {
    // Detects when x is unlikely to have a solution early in iterations
    if (x < 3 || (x % 3 != 0 && x % 7 != 0 && (x < 10 || x > 90))) {
        cerr << "Warning: Performance bottleneck condition triggered for x = " << x << "!" << endl;
        abort();
    }
}

// Checker function to monitor high iteration counts
void check_threshold_combinations(int x, int iterationCount) {
    if (iterationCount > 10000) {
        cerr << "Warning: High iteration count for x = " << x << "!" << endl;
        abort();
    }
}

// Checker for extensive iterations in no-solution cases
void check_no_solution_iterations(int x, bool foundSolution) {
    if (!foundSolution && x <= 10) {
        cerr << "Warning: Extensive iterations for no-solution case for x = " << x << "!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &(n));
    while (n--) {
        int x;
        scanf("%d", &(x));

        // Insert checker for repeated unsuccessful combinations
        check_unsuccessful_combinations(x);

        bool f = false;
        int iterationCount = 0;
        for (int i = 0; i <= 100; i++) {
            bool flag = false;
            for (int j = 0; j <= 100; j++) {
                iterationCount++;
                if (i * 3 + j * 7 == x) {
                    flag = 1;
                    f = 1;
                    break;
                }
            }
        }

        // Insert checker for high iteration counts
        check_threshold_combinations(x, iterationCount);

        // Insert checker for extensive iterations in no-solution cases
        check_no_solution_iterations(x, f);

        if (f)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}