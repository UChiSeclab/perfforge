#include <bits/stdc++.h>
using namespace std;

bool check(int x, int n, int g) {
    int low = 1, high = n;
    int iterations = 0; // Counter for iterations

    while (low <= high) {
        int mid = (low + high) >> 1;
        long long tmp = (long long)x * mid;
        if (tmp == g) return true;
        if (tmp < g)
            low = mid + 1;
        else
            high = mid - 1;

        iterations++; // Increment iteration count
    }

    // Check if binary search significantly exceeded expected number of iterations
    check_binary_search_iterations(iterations > 20);

    return false;
}

int main() {
    int n, x;
    while (scanf("%d%d", &n, &x) == 2) {
        int ans = 0;

        // Place checks before the loop to avoid overhead
        check_large_x_relative_to_n(x > n * n);
        check_large_table_minimal_matches(n > 10000 && ans < 10);

        for (int i = 1; i <= n; i++) {
            if (check(i, n, x)) ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}