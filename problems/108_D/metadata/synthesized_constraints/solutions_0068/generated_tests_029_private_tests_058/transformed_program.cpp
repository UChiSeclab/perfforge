#include <bits/stdc++.h>
using namespace std;

// Checker for high sum of students across departments
void check_high_sum_invariant(int sum, int n) {
    if (sum > 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - high sum of students across departments!" << endl;
        abort();
    }
}

// Checker for large difference between sum and specific department
void check_large_difference_invariant(int sum, int s, int n) {
    if (sum - s > 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - large difference between sum and specific department!" << endl;
        abort();
    }
}

// Checker for minimum requirement for players
void check_minimum_requirement_invariant(int sum, int s, int n) {
    if (s <= 2 && sum - s + 1 < n) {
        cerr << "Warning: Performance bottleneck condition triggered - minimum requirement for players!" << endl;
        abort();
    }
}

int main() {
    int n, m, h;
    int sum = 0;
    int s;
    
    // Read input values
    scanf("%d%d%d", &n, &m, &h);
    
    // Read student counts and compute sum
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        if (i == h) s = x;
    }
    
    // Insert performance checkers after input is read
    check_high_sum_invariant(sum, n);
    check_large_difference_invariant(sum, s, n);
    check_minimum_requirement_invariant(sum, s, n);
    
    if (sum < n) {
        printf("-1\n");
    } else {
        if (sum - s + 1 < n) {
            printf("1.0\n");
        } else {
            if (s == 1) {
                printf("0.0\n");
                return 0;
            }
            double ans = 0.0;
            for (int i = 1; i <= sum - s; i++) {
                ans += log((double)i);
            }
            for (int i = 1; i <= sum - n; i++) {
                ans += log((double)i);
            }
            for (int i = 1; i <= sum - 1; i++) {
                ans -= log((double)i);
            }
            for (int i = 1; i <= sum - s - n + 1; i++) {
                ans -= log((double)i);
            }
            printf("%.8lf\n", 1.0 - exp(ans));
        }
    }
    return 0;
}