#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_drying_bottleneck(int t1, int t2) {
    if (t2 < t1 / 2) {
        cerr << "Warning: Potential bottleneck - drying time much less than washing time!" << endl;
        abort();
    }
}

void check_folding_bottleneck(int n2, int n3, int t2, int t3) {
    if ((n3 < n2 / 2) && (t2 < t3 / 2)) {
        cerr << "Warning: Potential bottleneck - insufficient folding machines for drying rate!" << endl;
        abort();
    }
}

void check_machine_time_ratio(int n1, int n2, int n3, int t1, int t2, int t3) {
    if ((n1 / t1 < n2 / t2 / 2) || (n2 / t2 < n3 / t3 / 2)) {
        cerr << "Warning: Imbalance in machine-to-time ratio - potential resource contention!" << endl;
        abort();
    }
}

void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
    scanf("%d", &head);
    RI(tail...);
}

int main() {
    int n, m[5], t[5], c[5], x[10010], y[10010];
    RI(n);
    for (int i = (1); i <= int(3); i++) RI(m[i]);
    for (int i = (1); i <= int(3); i++) RI(t[i]);
    m[0] = m[4] = c[0] = n;

    // Inserted checker invocations after reading inputs
    check_drying_bottleneck(t[1], t[2]); // Check based on drying vs washing time
    check_folding_bottleneck(m[2], m[3], t[2], t[3]); // Check folding machine availability
    check_machine_time_ratio(m[1], m[2], m[3], t[1], t[2], t[3]); // Check machine-to-time ratios

    int ans = 0;
    while (1) {
        int mi = 1e9;
        for (int i = 0; i < int(n); i++)
            if (x[i] < 4 && c[x[i] + 1] < m[x[i] + 1]) {
                int dt = max(0, t[x[i]] - y[i]);
                if (dt < mi) mi = dt;
            }
        if (mi == 1e9) break;
        ans += mi;
        for (int i = 0; i < int(n); i++)
            if (x[i] < 4) {
                y[i] += mi;
                if (y[i] >= t[x[i]] && c[x[i] + 1] < m[x[i] + 1]) {
                    c[x[i]]--;
                    x[i]++;
                    c[x[i]]++;
                    y[i] = 0;
                }
            }
    }
    printf("%d\n", ans);
    return 0;
}