#include <bits/stdc++.h>
using namespace std;

int const inf = 1000000000;
int n;
vector<int> V;

int f(double d) {
    double cur = d;
    int p = 0;
    int i;
    for (i = 0; i < n; i++) {
        double use = (V[i] - p) * 10;
        double rem = cur - use;
        if (rem >= 10.0) return 2;
        if (rem < 0) return 0;
        cur = rem + d;
        p = V[i];
    }
    return 1;
}

int find_next(double d) {
    double cur = d;
    int p;
    p = 0;
    int i;
    for (i = 0; i < n; i++) {
        double use = (V[i] - p) * 10;
        double rem = cur - use;
        cur = rem + d;
        p = V[i];
    }
    int next = V.back();
    while (cur >= 10.0 || fabs(cur - 10) < 1e-9) cur -= 10, next++;
    return next;
}

// Check invariant 1: small n with large range of alpha
void check_small_n_large_range(int n, double low, double high) {
    if (n <= 2 && (high - low) > 1e6) { // Arbitrary large range threshold
        cerr << "Warning: Performance bottleneck - small n with large range of potential alpha values!" << endl;
        abort();
    }
}

// Check invariant 2: ambiguous stop pattern
void check_ambiguous_pattern(int result1, int result2) {
    if (result1 != result2) {
        cerr << "Warning: Performance bottleneck - ambiguous stop pattern leading to non-unique alpha determination!" << endl;
        abort();
    }
}

int main() {
    V.clear();
    cin >> n;
    int i;
    for (i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    double d;
    int t = 10000;
    double low, high, mid;
    low = 10;
    high = 1e8;

    // Insert check before starting the binary search
    check_small_n_large_range(n, low, high);

    while (t--) {
        mid = (low + high) / 2;
        int k = f(mid);
        if (k != 0)
            high = mid;
        else
            low = mid;
    }
    int next = find_next(mid);

    low = mid;
    high = 1e8;
    t = 10000;
    while (t--) {
        mid = (low + high) / 2;
        int k = f(mid);
        if (k == 2)
            high = mid;
        else
            low = mid;
    }
    int next2 = find_next(mid - 1e-9);

    // Insert check after determining both next and next2
    check_ambiguous_pattern(next, next2);

    if (next != next2)
        cout << "not unique" << endl;
    else
        cout << "unique\n" << next << endl;
    return 0;
}