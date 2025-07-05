#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
inline bool lt(double a, double b) { return a + eps < b; }
inline bool eq(double a, double b) { return !lt(a, b) && !lt(b, a); }
int n, s[1002];
double A, B, lo, hi, mid;

// Checker functions
void check_high_iteration_invariant(int n) {
    if (n > 900) { // Consider n close to the upper limit of 1000 as a trigger
        cerr << "Warning: High iteration invariant triggered - too many station stops leading to slow performance" << endl;
        abort();
    }
}

void check_sequence_complexity_invariant(const int s[], int n) {
    for (int i = 1; i < n; ++i) {
        if (s[i] - s[i-1] < 3) { // Consider closely spaced if less than 3 apart
            cerr << "Warning: Sequence complexity invariant triggered - stops are too closely spaced" << endl;
            abort();
        }
    }
}

void check_input_size_and_spread_invariant(const int s[], int n) {
    int max_index = s[n-1];
    int min_index = s[0];
    if ((max_index - min_index > 20) && (n > 5)) { // Arbitrary threshold for large spread
        cerr << "Warning: Input size and spread invariant triggered - large spread of stations" << endl;
        abort();
    }
}

int next(double mid) {
    double x = mid;
    int nxt = 0;
    for (int i = 0; i < n; ++i) {
        nxt += int(x / 10);
        x = fmod(x, 10) + mid;
    }
    nxt += int(x / 10);
    return nxt;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
    
    // Insert checks after reading input
    check_high_iteration_invariant(n);
    check_sequence_complexity_invariant(s, n);
    check_input_size_and_spread_invariant(s, n);
    
    lo = 10;
    hi = 10000000;
    for (int iter = 0; iter < 200; ++iter) {
        mid = (lo + hi) / 2;
        bool ok = true;
        double x = mid;
        int nxt = 0;
        for (int i = 0; i < n; ++i) {
            nxt += int(x / 10);
            if (nxt < s[i]) {
                ok = false;
                break;
            }
            if (nxt > s[i]) break;
            x = fmod(x, 10) + mid;
        }
        if (!ok)
            lo = mid + eps;
        else
            hi = mid;
    }
    A = mid;
    lo = 10;
    hi = 10000000;
    for (int iter = 0; iter < 200; ++iter) {
        mid = (lo + hi) / 2;
        bool ok = true;
        double x = mid;
        int nxt = 0;
        for (int i = 0; i < n; ++i) {
            nxt += int(x / 10);
            if (nxt > s[i]) {
                ok = false;
                break;
            }
            if (nxt < s[i]) break;
            x = fmod(x, 10) + mid;
        }
        if (!ok)
            hi = mid - eps;
        else
            lo = mid;
    }
    B = mid;
    int na = next(A);
    int nb = next(B);
    if (na == nb)
        printf("unique\n%d\n", na);
    else
        printf("not unique\n");
    return 0;
}