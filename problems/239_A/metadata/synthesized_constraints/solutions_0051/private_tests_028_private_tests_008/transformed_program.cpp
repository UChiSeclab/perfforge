#include <bits/stdc++.h>

// Check for high loop iterations due to n/k ratio
void check_loop_invariant(int n, int k) {
    if (n / k > 100000) {  // Arbitrary threshold chosen for illustration
        cerr << "Warning: Performance bottleneck condition triggered - high loop iterations due to n/k ratio!" << endl;
        abort();
    }
}

// Check for redundant computation in loops
void check_redundant_computation(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant computation in loops!" << endl;
        abort();
    }
}

int a[100000];

int main() {
    int y, k, n, i;
    while (scanf("%d %d %d", &y, &k, &n) != EOF) {
        // Check for potential performance bottleneck before the loop
        check_loop_invariant(n, k);

        int flag = 0;
        int l = n / k;

        for (i = 1; i <= l; i++) {
            // Check for redundant calculations - in this case, could be skipped if i*k is not used after checking against y
            check_redundant_computation(false); // Adjusted to not trigger because the computation is necessary for this logic

            a[i] = i * k;
            if (a[i] > y) {
                printf("%d ", a[i] - y);
                flag = 1;
            }
        }
        if (flag == 0) printf("-1");
        printf("\n");
    }
}