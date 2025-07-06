#include <bits/stdc++.h>
using namespace std;
const int max_n = 1111, inf = 1111111111;
int sum, n, m, h, s[max_n];

// Checker functions for performance bottlenecks
void check_large_sh_invariant(int sh, int n) {
    if (sh >= n) {
        cerr << "Warning: Performance bottleneck condition triggered - large s[h] relative to n!" << endl;
        abort();
    }
}

void check_sort_operations_invariant(int sh, int n) {
    if (sh > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive vector and sorting operations!" << endl;
        abort();
    }
}

void check_conditional_branching_invariant(int sh, int n) {
    if (sh >= n - 1) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching in nested loops!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> m >> h;
    --h;
    --n;
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
        if (i == h) {
            --s[i];
        }
        sum += s[i];
    }
    if (sum < n) {
        cout << -1 << endl;
        return 0;
    }

    // Perform checks after input and setup
    check_large_sh_invariant(s[h], n);
    check_sort_operations_invariant(s[h], n);
    check_conditional_branching_invariant(s[h], n);

    double ans = 0;
    for (int i = 1; i <= s[h] && i <= n; ++i) {
        double v = 1;
        vector<int> q1, q2;
        for (int j = 2; j <= s[h]; ++j) {
            q1.push_back(j);
        }
        for (int j = n - i + 1; j <= n; ++j) {
            q1.push_back(j);
        }
        for (int j = sum - n - s[h] + i + 1; j <= sum - n; ++j) {
            q1.push_back(j);
        }
        for (int j = 2; j <= i; ++j) {
            q2.push_back(j);
        }
        for (int j = 2; j <= s[h] - i; ++j) {
            q2.push_back(j);
        }
        for (int j = sum - s[h] + 1; j <= sum; ++j) {
            q2.push_back(j);
        }
        sort(q1.begin(), q1.end());
        sort(q2.begin(), q2.end());
        reverse(q2.begin(), q2.end());
        for (int j = 0; j < max(q1.size(), q2.size()); ++j) {
            if (j < q1.size()) {
                v *= q1[j];
            }
            if (j < q2.size()) {
                v /= q2[j];
            }
        }
        ans += v;
    }
    printf("%.10f\n", ans);
    return 0;
}