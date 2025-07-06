#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
const long long INFINITE = 0x7FFFFFFFFFFFFFFFll;
int n;
long long m, res;
long long tem[MAXN], bnd[MAXN], mon[MAXN], car[MAXN];
inline long long min(long long x, long long y) { return (x < y) ? x : y; }

void check_high_compensation_invariant(long long xi, long long costi, long long tem_i, long long Ti, long long m) {
    if (xi > costi && (tem_i + m) > Ti && (Ti - tem_i) <= 5) {
        cerr << "Warning: High compensation costs triggered!" << endl;
        abort();
    }
}

void check_large_children_tight_margin_invariant(long long m, long long tem_i, long long Ti) {
    if (m > 1000 && (Ti - tem_i) <= 5) {
        cerr << "Warning: Large number of children with tight temperature margin triggered!" << endl;
        abort();
    }
}

void check_boundary_conditions_invariant(long long tem_i, long long Ti) {
    if (tem_i >= Ti) {
        cerr << "Warning: Frequent boundary conditions triggered!" << endl;
        abort();
    }
}

void check_high_variability_invariant(long long min_Ti, long long max_Ti) {
    if ((max_Ti - min_Ti) > 50) {
        cerr << "Warning: High variability in region conditions triggered!" << endl;
        abort();
    }
}

int main() {
    scanf("%d %I64d\n", &n, &m);
    long long min_Ti = INFINITE, max_Ti = -INFINITE;
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d %I64d %I64d %I64d\n", &tem[i], &bnd[i], &mon[i], &car[i]);
        min_Ti = min(min_Ti, bnd[i]);
        max_Ti = max(max_Ti, bnd[i]);
    }
    
    check_high_variability_invariant(min_Ti, max_Ti);

    long long tmp;
    for (int i = 1; i <= n; ++i) {
        check_high_compensation_invariant(mon[i], car[i], tem[i], bnd[i], m);
        check_large_children_tight_margin_invariant(m, tem[i], bnd[i]);
        check_boundary_conditions_invariant(tem[i], bnd[i]);

        if (bnd[i] <= tem[i]) {
            res += car[i] + m * mon[i];
        } else {
            long long num = m / (bnd[i] - tem[i]) + (m % (bnd[i] - tem[i]) > 0);
            if (tem[i] + m > bnd[i])
                res += tmp = min(car[i] + m * mon[i], num * car[i]);
            else
                res += tmp = min(car[i], num * car[i]);
        }
    }
    printf("%I64d\n", res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}