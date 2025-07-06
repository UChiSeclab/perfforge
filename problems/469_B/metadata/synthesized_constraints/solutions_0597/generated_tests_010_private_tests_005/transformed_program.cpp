#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
const long double EPS = 1.0E-14;
bool check[2005];
set<long long> st;

// Checker functions
void check_large_overlap(int overlap_count) {
    if (overlap_count > 10000) {  // Threshold chosen based on expected overlap
        cerr << "Warning: Performance bottleneck condition triggered - large overlapping ranges!" << endl;
        abort();
    }
}

void check_high_density(int active_count) {
    if (active_count > 5000) {  // Threshold for high density
        cerr << "Warning: Performance bottleneck condition triggered - high density of active times!" << endl;
        abort();
    }
}

void check_large_range(int range_size) {
    if (range_size > 100) {  // Arbitrary threshold for a large range size
        cerr << "Warning: Performance bottleneck condition triggered - large range sizes!" << endl;
        abort();
    }
}

int main() {
    long long p, q, l, r, x, y, newX, newY;
    cin >> p >> q >> l >> r;
    
    for (int i = 0; i < p; i++) {
        scanf("%lld %lld", &x, &y);
        for (int j = x; j <= y; j++) {
            check[j] = true;
        }
    }

    int overall_overlap_count = 0;  // To track total overlaps
    int active_count = 0;           // To track active overlapping times

    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &x, &y);
        for (int j = l; j <= r; j++) {
            newX = x + j, newY = y + j;
            check_large_range(newY - newX);  // Check for large range size
            int overlap_count = 0;  // Count for each new range
            for (int k = newX; k <= newY; k++) {
                if (check[k]) {
                    st.insert(j);
                    overlap_count++;
                    active_count++;
                    break;
                }
            }
            overall_overlap_count += overlap_count;
            check_high_density(active_count);  // Check high density of active times
        }
    }
    check_large_overlap(overall_overlap_count);  // Check for large overall overlaps
    cout << st.size();
}