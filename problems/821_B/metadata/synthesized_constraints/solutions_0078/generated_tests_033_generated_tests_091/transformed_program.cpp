#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_large_b_invariant(long long b) {
    if (b > 5000) {  // Threshold for 'b' indicating potential performance bottleneck
        cerr << "Warning: Performance bottleneck due to large 'b' value triggering excessive iterations!" << endl;
        abort();
    }
}

void check_large_rectangle_invariant(long long m, long long b) {
    if (m * b > 5000000) {  // Threshold for rectangle area leading to too many iterations
        cerr << "Warning: Performance bottleneck due to large rectangle area leading to high loop count!" << endl;
        abort();
    }
}

void check_accumulation_invariant(long long b) {
    if (b > 3000) {  // Threshold for excessive sum accumulation in loops
        cerr << "Warning: Performance bottleneck caused by excessive accumulation in nested loops!" << endl;
        abort();
    }
}

int main() {
    long long m, b;
    cin >> m >> b;

    // Insert checker calls after input
    check_large_b_invariant(b);
    check_large_rectangle_invariant(m, b);
    check_accumulation_invariant(b);

    long long y = b;
    long long x = b * m;
    long long max1 = 0;
    for (long long iy = b; iy >= 0; iy--) {
        long long ix = m * (b - iy);
        long long sum = 0;
        long long sumx = (ix * (ix + 1)) / 2;
        for (long long j = iy; j >= 0; j--) {
            long long sumy = (ix + 1) * j;
            sum += sumx + sumy;
        }
        if (max1 < sum) max1 = sum;
    }
    cout << max1 << endl;
    return 0;
}