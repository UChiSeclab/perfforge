#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_large_i_invariant(int i, int n, int p) {
    if (p > 0 && i > n / p) {
        cerr << "Warning: Performance bottleneck condition triggered - large i due to n being close to or smaller than p!" << endl;
        abort();
    }
}

void check_large_tmp_invariant(int tmp) {
    if (tmp > (1 << 20)) {  // Example threshold; adjust based on understanding of tmp's potential size
        cerr << "Warning: Performance bottleneck condition triggered - large tmp leading to excessive binary conversion!" << endl;
        abort();
    }
}

void check_impossible_condition(int cnt, int i, int tmp, int n, int p) {
    if (i >= n && cnt > i && tmp < 0) {
        cerr << "Warning: Performance bottleneck condition triggered - impossible conditions due to high p!" << endl;
        abort();
    }
}

int main() {
    int n, p;
    scanf("%d%d", &n, &p);

    for (int i = 0; i <= 1000000; i++) {
        check_large_i_invariant(i, n, p);  // Check for the large `i` invariant

        int tmp = n - p * i;
        check_large_tmp_invariant(tmp);  // Check for large `tmp` invariant

        int cnt = 0;
        while (tmp) {
            cnt += tmp % 2;
            tmp /= 2;
        }

        check_impossible_condition(cnt, i, tmp, n, p);  // Check for impossible condition

        if (cnt <= i && i <= n - p * i) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}