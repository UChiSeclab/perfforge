#include <bits/stdc++.h>
using namespace std;

int ar[10001], ar2[10001];
int cc[10001];

void check_large_range_invariant(int l, int r) {
    if (r - l > 900) {  // Threshold based on input constraints
        cerr << "Warning: Performance bottleneck condition triggered - large range of wake-up times!" << endl;
        abort();
    }
}

void check_dense_overlap_invariant(int p, int q) {
    if (p * q > 1000) {  // Threshold based on typical overlap causing slow behavior
        cerr << "Warning: Performance bottleneck condition triggered - dense overlapping segments!" << endl;
        abort();
    }
}

void check_high_segments_invariant(int p, int q) {
    if (p >= 45 || q >= 45) {  // Threshold when segment count is close to the upper limit
        cerr << "Warning: Performance bottleneck condition triggered - high number of time segments!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int p, q, r, l;
    cin >> p >> q >> l >> r;

    // Insert performance checks here
    check_large_range_invariant(l, r);
    check_dense_overlap_invariant(p, q);
    check_high_segments_invariant(p, q);

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) ar[j] = 1;
    }

    int z = 0;
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            for (int p = l; p <= r; p++) {
                if (ar[p + j] == 1) {
                    cc[p] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < 1001; i++) z += cc[i];
    cout << z;
    return 0;
}