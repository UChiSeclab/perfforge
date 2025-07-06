#include <bits/stdc++.h>

int a[1000002] = {0};

// Define checker functions here
void check_max_length_invariant(long long max_length) {
    if (max_length > 1000000) {
        cerr << "Warning: Performance bottleneck - maximum stick length is too large!" << endl;
        abort();
    }
}

void check_identical_lengths_invariant(const int* array, int size) {
    int threshold = 50000;
    for (int i = 0; i < size; ++i) {
        if (array[i] > threshold) {
            cerr << "Warning: Performance bottleneck - too many sticks of the same length!" << endl;
            abort();
        }
    }
}

void check_pairing_imbalance_invariant(int rect_count) {
    if (rect_count < 1) {
        cerr << "Warning: Performance bottleneck - imbalance in stick pairing!" << endl;
        abort();
    }
}

int main() {
    int m, n;
    int mm, nn;
    long long int w, ww, x, xx, y, yy, z, zz;
    
    // Read input
    scanf("%d", &nn);
    mm = 0;
    y = 0;
    
    while (mm < nn) {
        scanf("%lld", &x);
        if (x > y) {
            y = x;
        }
        a[x - 1]++;
        mm++;
    }
    
    // Check for maximum stick length invariant
    check_max_length_invariant(y);
    
    z = 0;
    w = 0;
    ww = 0;
    xx = y;
    
    // Check for identical lengths invariant
    check_identical_lengths_invariant(a, y + 1);
    
    while (xx >= 0) {
        if (w != 0 && ww != 0) {
            z = z + w * ww;
            w = 0;
            ww = 0;
        }
        if (a[xx] >= 2) {
            if (w == 0) {
                w = xx + 1;
                a[xx] = a[xx] - 2;
            } else if (ww == 0) {
                ww = xx + 1;
                a[xx] = a[xx] - 2;
            }
            continue;
        } else if (a[xx] == 1 && a[xx - 1] >= 1) {
            if (w == 0) {
                w = xx;
            } else if (ww == 0) {
                ww = xx;
            }
            a[xx] = a[xx] - 1;
            a[xx - 1] = a[xx - 1] - 1;
        }
        xx--;
    }
    
    // Check for pairing imbalance invariant
    int rect_count = (z > 0) ? 1 : 0; // An approximation of successful pairings
    check_pairing_imbalance_invariant(rect_count);
    
    printf("%lld\n", z);
    return 0;
}