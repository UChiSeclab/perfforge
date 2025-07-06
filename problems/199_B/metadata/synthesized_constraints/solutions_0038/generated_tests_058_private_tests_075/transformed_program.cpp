#include <bits/stdc++.h>
using namespace std;

void check_large_range_invariant(long long r2, long long R2) {
    if ((R2 - r2) > 50000) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - Large range in second ring." << endl;
        abort();
    }
}

void check_overlap_invariant(long long dis, long long r1, long long R1, long long r2, long long R2) {
    if ((R2 - r2) > 50000 && dis < (R2 + R1) * (R2 + R1) && dis > (R2 - r1) * (R2 - r1)) {
        cerr << "Warning: Performance bottleneck condition triggered - Overlapping radii causing many iterations." << endl;
        abort();
    }
}

int main() {
    long long int x1, y1, x2, y2, r1, R1, r2, R2;
    cin >> x1 >> y1 >> r1 >> R1;
    cin >> x2 >> y2 >> r2 >> R2;
    x1 *= 10000;
    x2 *= 10000;
    y1 *= 10000;
    y2 *= 10000;
    r1 *= 10000;
    r2 *= 10000;
    R1 *= 10000;
    R2 *= 10000;
    
    // Check for performance bottlenecks
    check_large_range_invariant(r2, R2);
    long long dis = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    check_overlap_invariant(dis, r1, R1, r2, R2);

    vector<bool> good(4, true);
    for (long long int rad = r1; rad <= R1; ++rad) {
        if ((dis < (rad + r2) * (rad + r2)) && (dis > (rad - r2) * (rad - r2))) {
            good[2] = false;
        }
        if ((dis < (rad + R2) * (rad + R2)) && (dis > (rad - R2) * (rad - R2))) {
            good[3] = false;
        }
    }
    for (long long int rad = r2; rad <= R2; ++rad) {
        if ((dis < (rad + r1) * (rad + r1)) && (dis > (rad - r1) * (rad - r1))) {
            good[1] = false;
        }
        if ((dis < (rad + R1) * (rad + R1)) && (dis > (rad - R1) * (rad - R1))) {
            good[0] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        if (good[i]) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}