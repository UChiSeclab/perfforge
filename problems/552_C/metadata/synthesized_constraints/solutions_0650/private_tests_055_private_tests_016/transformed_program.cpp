#include <bits/stdc++.h>
using namespace std;

long long int a[200], w, m, dp[200][4], i = 0;
bool mm = 0;

void check_small_base_invariant(long long int w) {
    if (w < 10) { // Threshold chosen due to significant slowdown observed for small w
        cerr << "Warning: Performance bottleneck condition triggered due to small base w!" << endl;
        abort();
    }
}

void check_large_search_space_invariant(int elements_count) {
    if (elements_count > 20) { // Assuming a reasonable threshold for recursion depth
        cerr << "Warning: Performance bottleneck condition triggered due to large search space!" << endl;
        abort();
    }
}

void asdd(long long int q, int s) {
    // Check recursion depth before proceeding
    check_recursion_depth_invariant(s);

    if (s == i + 1) {
        if (q == 0) mm = 1;
        return;
    }
    asdd(q, s + 1);
    asdd(q + a[s], s + 1);
    asdd(q - a[s], s + 1);
}

int main() {
    cin >> w >> m;

    // Check the small base invariant after reading inputs
    check_small_base_invariant(w);

    if (w == 2 || w == 3) {
        cout << "YES";
        return 0;
    }

    a[0] = 1;
    while (a[i] <= 2 * 1e9) {
        i++;
        a[i] = a[i - 1] * w;
    }

    // Check large search space invariant before recursion begins
    check_large_search_space_invariant(i);

    asdd(m, 0);

    if (mm)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}