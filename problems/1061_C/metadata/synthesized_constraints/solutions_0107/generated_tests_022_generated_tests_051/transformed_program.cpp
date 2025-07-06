#include <bits/stdc++.h>
using namespace std;

vector<int> x[1000005];
int a[100005];
long long f[1000005];

void check_max_value_invariant(int max_value) {
    if (max_value > 500000) { // Threshold chosen based on problem constraints and observations
        cerr << "Warning: Performance bottleneck condition triggered - maximum value in array is very large!" << endl;
        abort();
    }
}

void check_divisor_count_invariant(const vector<int> x[], int mx) {
    for (int i = 1; i <= mx; ++i) {
        if (x[i].size() > 200) { // Arbitrary threshold indicating a large number of divisors
            cerr << "Warning: Performance bottleneck condition triggered - number has many divisors!" << endl;
            abort();
        }
    }
}

void check_sorting_invariant(const vector<int> x[], int mx) {
    for (int i = 1; i <= mx; ++i) {
        if (x[i].size() > 100) { // Threshold indicating large divisor collections need sorting
            cerr << "Warning: Performance bottleneck condition triggered - sorting large data!" << endl;
            abort();
        }
    }
}

void check_loop_bound_invariant(int max_value) {
    if (max_value > 750000) { // Conservative threshold for loop bounds based on mx
        cerr << "Warning: Performance bottleneck condition triggered - large loop bounds!" << endl;
        abort();
    }
}

int main() {
    int n, i, mx = 0, j;
    long long ans = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        mx = max(a[i], mx);
    }

    // Insert checks here after input is processed and maximum value is determined
    check_max_value_invariant(mx);
    check_loop_bound_invariant(mx);

    for (i = 1; i <= mx; ++i) {
        for (j = i; j <= mx; j += i) {
            x[j].push_back(i);
        }
    }

    // Check the number of divisors collected and sorting impact
    check_divisor_count_invariant(x, mx);

    for (i = 1; i <= mx; ++i) {
        sort(x[i].begin(), x[i].end());
    }

    // Check sorting after it is performed
    check_sorting_invariant(x, mx);

    f[0] = 1;
    for (i = 1; i <= n; ++i) {
        for (j = x[a[i]].size() - 1; j >= 0; --j) {
            f[x[a[i]][j]] = (f[x[a[i]][j]] + f[x[a[i]][j] - 1]) % 1000000007ll;
        }
    }

    for (i = 1; i <= n; ++i) {
        ans = (ans + f[i]) % 1000000007ll;
    }

    printf("%lld", ans);
}