#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int a[N], b[N], cnt[N], useda[N], usedb[N], c[N], d[N], gooda[N], goodb[N],
    wwa[N], wwb[N];
int n, m;

// Checker functions based on invariants
void check_iteration_invariant(int n, int m, int it) {
    if (n > 6 && m > 6 && it > 20) { // Update thresholds based on expected performance
        cerr << "Warning: iteration_invariant triggered - excessive nested loop iterations" << endl;
        abort();
    }
}

void check_redundant_checks_invariant(int condition_count, int threshold) {
    if (condition_count > threshold) { // Threshold based on expected efficiency
        cerr << "Warning: redundant_checks_invariant triggered - redundant condition checks" << endl;
        abort();
    }
}

void check_pruning_invariant(int initial_n, int initial_m, int current_n, int current_m) {
    if (current_n == initial_n && current_m == initial_m) {
        cerr << "Warning: pruning_invariant triggered - ineffective reduction of data size" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int initial_n = n, initial_m = m; // Save initial n and m for pruning check
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= m; i++) cin >> c[i] >> d[i];
    int it = 0;
    int condition_count = 0; // Counter for redundant condition checks
    while (n > 0 && m > 0 && it < 100) {
        for (int i = 1; i <= 12; i++)
            useda[i] = usedb[i] = cnt[i] = 0, gooda[i] = 1, goodb[i] = 1, wwa[i] = -1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                int t = 0;
                if (a[i] == c[j]) t++;
                if (b[i] == c[j]) t++;
                if (a[i] == d[j]) t++;
                if (b[i] == d[j]) t++;
                if (t == 1) {
                    useda[i]++;
                    usedb[j]++;
                    if (a[i] == c[j]) t = a[i];
                    if (b[i] == c[j]) t = b[i];
                    if (a[i] == d[j]) t = a[i];
                    if (b[i] == d[j]) t = b[i];
                    cnt[t]++;
                    if (useda[i] >= 2 && t != wwa[i]) gooda[i] = 0;
                    if (usedb[j] >= 2 && t != wwb[j]) goodb[j] = 0;
                    wwa[i] = t;
                    wwb[j] = t;
                    condition_count++; // Increment condition checks
                }
            }
        check_redundant_checks_invariant(condition_count, 50); // Check for redundant condition execution

        int q = 0, last;
        for (int i = 1; i <= 12; i++)
            if (cnt[i] > 0) {
                q++;
                last = i;
            }
        if (q == 1) {
            cout << last << "\n";
            return 0;
        }
        int cn = 0;
        for (int i = 1; i <= n; i++)
            if (useda[i]) {
                cn++;
                a[cn] = a[i];
                b[cn] = b[i];
            }
        n = cn;
        cn = 0;
        for (int i = 1; i <= m; i++)
            if (usedb[i]) {
                cn++;
                c[cn] = c[i];
                d[cn] = d[i];
            }
        m = cn;
        check_pruning_invariant(initial_n, initial_m, n, m); // Check effective pruning
        it++;
        check_iteration_invariant(n, m, it); // Check iteration count
    }
    int ok = 0;
    for (int i = 1; i <= n; i++)
        if (gooda[i]) ok++;
    for (int i = 1; i <= m; i++)
        if (goodb[i]) ok++;
    if (ok == n + m) {
        cout << "0\n";
        return 0;
    } else
        cout << "-1\n";
    return 0;
}