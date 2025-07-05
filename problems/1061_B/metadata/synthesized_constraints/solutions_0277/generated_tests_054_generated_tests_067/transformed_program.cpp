#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long n, m, ar[N], ans, mx, res[N];

// Checkers for performance invariants
void check_large_n_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of stacks with variable heights!" << endl;
        abort();
    }
}

void check_input_diversity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to significant height variations!" << endl;
        abort();
    }
}

void check_balanced_inputs_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to balanced stack heights causing maximum decrements!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%I64d", &ar[i]);

    // Check for potential performance bottlenecks before sorting
    check_large_n_invariant(n > 95); // example threshold close to the upper bound

    sort(ar + 1, ar + n + 1);

    // Check for input diversity impact after sorting
    check_input_diversity_invariant(ar[n] - ar[1] > m / 2); // significant variation threshold

    mx = ar[n] - 1;
    for (int i = n - 1; i >= 1; i--) {
        ans += ar[i] - 1;
        mx = min(mx, ar[i]);
        if (mx > 0) mx--, ans++;
    }

    // Check for balanced inputs causing maximum decrements
    check_balanced_inputs_invariant(mx == 0); // condition where all decrements are possible

    cout << ans << endl;
}