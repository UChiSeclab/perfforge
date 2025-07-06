#include <bits/stdc++.h>
using namespace std;

long long n, p, x, an, ans, MAXN = 1e9;

// Check if the loop will iterate excessively due to insufficient reduction in n
void check_loop_invariant(long long n, long long p) {
    if (n > 1e9 && p >= 0) {
        cerr << "Warning: Loop invariant triggered - possible excessive iterations due to large n and non-negative p" << endl;
        abort();
    }
}

// Check if excessive bit operations are likely due to large n
void check_bit_operations_invariant(int i, long long n, long long p) {
    if (i > 1e6 && n - i*p > 0) {
        cerr << "Warning: Bit operations invariant triggered - excessive bit operations for large n and small decrement" << endl;
        abort();
    }
}

// Check if the search space remains large with insufficient reduction in each iteration
void check_search_space_invariant(long long n, long long p, int i) {
    if ((n - i*p) > 1e8 && i > 500000) {
        cerr << "Warning: Search space invariant triggered - large search space due to insufficient decrement" << endl;
        abort();
    }
}

int main() {
    scanf("%lld%lld", &n, &p);

    // Check for potential loop inefficiency before starting the main loop
    check_loop_invariant(n, p);

    ans = MAXN;
    for (int i = 1; i <= 1000000; i++) {
        n = n - p;
        if (n <= 0ll) break;
        x = n;
        an = 0;
        
        // Check for potential excessive bit operations before entering the while loop
        check_bit_operations_invariant(i, n, p);

        while (x) {
            an += x & 1;
            x >>= 1;
        }
        
        // Check for large search space inefficiency after critical operations
        check_search_space_invariant(n, p, i);

        if (i >= an && n >= i) ans = min(ans, (long long)i);
    }
    if (ans == MAXN)
        printf("-1");
    else
        printf("%lld", ans);
}