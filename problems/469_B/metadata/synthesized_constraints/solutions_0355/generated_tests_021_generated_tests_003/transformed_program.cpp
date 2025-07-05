#include <bits/stdc++.h>
using namespace std;

int p, q, l, r, i, a, b, online[2010], S[1010], F[1010], sol, j, k, ok;

// Checker functions
void check_large_overlap_invariant(int l, int r, int q, int* S, int* F) {
    int shiftRange = r - l + 1;
    int totalSegmentsLength = 0;
    for (int j = 1; j <= q; j++) {
        totalSegmentsLength += (F[j] - S[j] + 1);
    }
    if (shiftRange * totalSegmentsLength > 50000) { // This threshold can be adjusted
        cerr << "Warning: large_overlap_invariant triggered - excessive operations due to large overlaps" << endl;
        abort();
    }
}

void check_wide_shift_range_invariant(int l, int r) {
    if (r - l > 100) { // Assuming 100 as a reasonable threshold for wide range
        cerr << "Warning: wide_shift_range_invariant triggered - wide range of shift times" << endl;
        abort();
    }
}

void check_high_overlap_checks_invariant(int q, int* S, int* F) {
    int averageSegmentLength = 0;
    for (int j = 1; j <= q; j++) {
        averageSegmentLength += (F[j] - S[j] + 1);
    }
    averageSegmentLength /= q;
    if (averageSegmentLength > 50) { // Assuming 50 as a reasonable threshold
        cerr << "Warning: high_overlap_checks_invariant triggered - frequent overlap checks" << endl;
        abort();
    }
}

int main() {
    cin >> p >> q >> l >> r;
    for (i = 1; i <= p; i++) {
        cin >> a >> b;
        for (j = a; j <= b; j++) online[j] = 1;
    }
    for (i = 1; i <= q; i++) {
        cin >> S[i] >> F[i];
    }

    // Insert the performance checks after input reading
    check_large_overlap_invariant(l, r, q, S, F);
    check_wide_shift_range_invariant(l, r);
    check_high_overlap_checks_invariant(q, S, F);

    for (i = l; i <= r; i++) {
        ok = 0;
        for (j = 1; j <= q; j++) {
            for (k = S[j]; k <= F[j]; k++)
                if (online[i + k]) ok = 1;
        }
        sol = sol + ok;
    }
    cout << sol;
    return 0;
}