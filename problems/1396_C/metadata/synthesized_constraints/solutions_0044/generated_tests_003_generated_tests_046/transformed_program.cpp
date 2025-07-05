#include <bits/stdc++.h>
using namespace std;

long long n, r1, r2, r3, tim;
long long a[1000010], d[1000010];

// Checker functions
void check_large_monster_count(long long monsterCount, long long threshold) {
    if (monsterCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - monster count too large in a level!" << endl;
        abort();
    }
}

void check_high_teleportation_frequency(long long nLevels, long long teleportTime, long long threshold) {
    if (nLevels * teleportTime > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high teleportation frequency!" << endl;
        abort();
    }
}

void check_reload_time_variance(long long r1, long long r2, long long r3, long long varianceThreshold) {
    if ((r3 - r1) > varianceThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high reload time variance!" << endl;
        abort();
    }
}

int main() {
    scanf("%lld%lld%lld%lld%lld", &n, &r1, &r2, &r3, &tim);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    // Performance checks
    check_large_monster_count(*max_element(a + 1, a + n + 1), 500000); // Example threshold
    check_high_teleportation_frequency(n, tim, 100000000); // Example threshold
    check_reload_time_variance(r1, r2, r3, 100000000); // Example threshold

    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + (i == 1 ? 0 : tim) + r1 * a[i] + r3;
        d[i] = min(d[i], d[i - 1] + (i == 1 ? 0 : tim) + min(r2, r1 * a[i] + r1) +
                             2 * tim + r1);
        if (i >= 2) {
            d[i] = min(d[i], d[i - 2] + (i - 1 == 1 ? 0 : tim) +
                               min(r2, r1 * a[i - 1] + r1) + tim +
                               min(r2, r1 * a[i] + r1) + tim + 2 * r1 + tim);
            d[i] = min(d[i], d[i - 2] + (i - 1 == 1 ? 0 : tim) +
                               min(r2, r1 * a[i - 1] + r1) + tim + r1 * a[i] + r3 +
                               tim + r1 + tim);
        }
    }
    long long res = d[n];
    res =
        min(res, d[n - 2] + (n - 1 == 1 ? 0 : tim) + min(r2, r1 * a[n - 1] + r1) +
                     tim + min(r2, r1 * a[n] + r1) + 2 * tim + 2 * r1);
    res =
        min(res, d[n - 2] + (n - 1 == 1 ? 0 : tim) + min(r2, r1 * a[n - 1] + r1) +
                     tim + r1 * a[n] + r3 + tim + r1);
    printf("%lld", res);
    return 0;
}