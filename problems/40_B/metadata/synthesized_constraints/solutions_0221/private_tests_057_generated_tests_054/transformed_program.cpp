#include <bits/stdc++.h>
using namespace std;

bool arr[5005][5005];

void check_loop_invariant(int n, int m) {
    if (n > 1000 || m > 1000) {  // Example threshold to detect large loops
        cerr << "Warning: Performance bottleneck condition triggered - large adjusted dimensions in loops!" << endl;
        abort();
    }
}

void check_boundary_invariant(int n, int m) {
    if (n * m > 1000000) {  // Example threshold to detect high boundary checks
        cerr << "Warning: Performance bottleneck condition triggered - excessive boundary checks!" << endl;
        abort();
    }
}

void check_high_iterative_invariant(int n, int m, int x) {
    if ((n > 1000 || m > 1000) && x > 1000) {  // Threshold for large dimensions and x
        cerr << "Warning: Performance bottleneck condition triggered - large input size with high iterations!" << endl;
        abort();
    }
}

int main() {
    int i, a, n, m, x, ret = 0;
    scanf("%d %d %d", &n, &m, &x);

    // Placing the checkers right after input is read
    check_high_iterative_invariant(n, m, x);

    // Adjust dimensions
    n -= 2 * (x - 1);
    m -= 2 * (x - 1);

    // Check if adjusted dimensions are large before entering loops
    check_loop_invariant(n, m);
    check_boundary_invariant(n, m);

    if (n <= 0 && m <= 0)
        printf("0\n");
    else {
        for (i = 0; i < n; i++) {
            if (i % 2 == 0)
                arr[i][0] = 1;
            else
                arr[i][0] = 0;
            for (a = 1; a < m; a++) arr[i][a] = !arr[i][a - 1];
        }
        for (i = 0; i < n; i++)
            for (a = 0; a < m; a++)
                if (i == 0 || i == n - 1 || a == 0 || a == m - 1) ret += arr[i][a];
        printf("%d\n", ret);
    }
    return 0;
}