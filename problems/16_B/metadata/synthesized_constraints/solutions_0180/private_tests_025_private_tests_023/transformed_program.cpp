#include <bits/stdc++.h>
using namespace std;

void check_total_matchboxes_invariant(long totalMatchboxes) {
    if (totalMatchboxes > 1e9) {  // Arbitrary large threshold for total matchboxes
        cerr << "Warning: Performance bottleneck condition triggered - total matchboxes too large!" << endl;
        abort();
    }
}

void check_single_container_invariant(long maxMatchboxesInContainer, long numContainers) {
    if (maxMatchboxesInContainer > 1e8 && numContainers > 1e7) {  // Thresholds considering constraints
        cerr << "Warning: Performance bottleneck condition triggered - single container too large!" << endl;
        abort();
    }
}

void check_capacity_invariant(long currentCapacity, long maxCapacity) {
    if (currentCapacity >= maxCapacity * 0.95) {  // Near-max capacity
        cerr << "Warning: Performance bottleneck condition triggered - near-max capacity utilization!" << endl;
        abort();
    }
}

int main() {
    long int p, a[20][2];
    int n, m, i, j, k, l, t, u, pos, s = 0;
    cin >> p >> n;
    long totalMatchboxes = 0;
    long maxMatchboxesInContainer = 0;

    for (i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        totalMatchboxes += a[i][0];
        if (a[i][0] > maxMatchboxesInContainer) maxMatchboxesInContainer = a[i][0];
    }

    // Invariant checks after reading input
    check_total_matchboxes_invariant(totalMatchboxes);
    check_single_container_invariant(maxMatchboxesInContainer, n);

    for (i = 0; i < n - 1; i++) {
        t = a[i][1];
        for (j = i + 1; j < n; j++) {
            if (t < a[j][1]) {
                t = a[j][1];
                u = a[j][0];
                pos = j;
            }
            l = a[i][1];
            m = a[i][0];
            if (t != l) {
                a[i][1] = t;
                a[i][0] = u;
                a[pos][1] = l;
                a[pos][0] = m;
            }
        }
    }
    for (i = 0; i < n; i++) l = 1;
    m = 0;
    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 1; j <= a[i][0]; j++) {
            m += a[i][1] * l;
            s += l;
            if (s == p) {
                k++;
                break;
            }
        }
        if (k > 0) break;
    }

    // Invariant check before output
    check_capacity_invariant(s, p);

    cout << m;
    return 0;
}