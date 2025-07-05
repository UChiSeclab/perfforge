#include <bits/stdc++.h>

using namespace std;

void check_machine_availability_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to insufficient machine availability!" << endl;
        abort();
    }
}

void check_drying_bottleneck_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to drying stage being a bottleneck!" << endl;
        abort();
    }
}

void check_stage_time_imbalance_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to time imbalance between stages!" << endl;
        abort();
    }
}

void check_parallelization_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to inadequate parallelization of machines!" << endl;
        abort();
    }
}

int main() {
    int k, n[3], t[3];
    int c[3];
    int d[3];
    int a[10000];
    int b[10000];
    int inf = 100000000;

    while (scanf("%d%d%d%d%d%d%d", &k, n, n + 1, n + 2, t, t + 1, t + 2) != EOF) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int now = 0;
        int temp = t[0];
        int temp2;

        // Check machine availability invariant
        check_machine_availability_invariant((n[0] < k / 3) || (n[1] < k / 3) || (n[2] < k / 3));

        // Check drying bottleneck invariant
        check_drying_bottleneck_invariant(n[1] < n[0] && t[1] > t[0]);

        // Check stage time imbalance invariant
        check_stage_time_imbalance_invariant((t[0] > 2 * t[1]) || (t[1] > 2 * t[2]));

        // Check parallelization invariant
        check_parallelization_invariant((n[0] < n[1]) || (n[1] < n[2]));

        while (1) {
            now += temp;
            temp2 = inf;
            for (int i = 0; i < k; i++)
                if (a[i] < 3) {
                    if (temp + b[i] >= t[a[i]]) {
                        if (!b[i] && c[a[i]] == n[a[i]]) {
                            temp2 = (t[a[i]] - b[i] < temp2 ? t[a[i]] - b[i] : temp2);
                            continue;
                        }
                        if (!b[i]) c[a[i]]++;
                        d[a[i]]++;
                        b[i] += temp - t[a[i]];
                        a[i]++;
                        if (b[i]) {
                            if (c[a[i]] < n[a[i]])
                                c[a[i]]++;
                            else
                                b[i] = 0;
                        }
                    } else if (b[i])
                        b[i] += temp;
                    else if (c[a[i]] < n[a[i]]) {
                        c[a[i]]++;
                        b[i] = temp;
                    }
                    if (a[i] < 3)
                        temp2 = (t[a[i]] - b[i] < temp2 ? t[a[i]] - b[i] : temp2);
                }
            if (temp2 == inf) break;
            for (int i = 0; i < 3; i++) {
                c[i] -= d[i];
                d[i] = 0;
            }
            temp = temp2;
        }
        printf("%d\n", now);
    }
}