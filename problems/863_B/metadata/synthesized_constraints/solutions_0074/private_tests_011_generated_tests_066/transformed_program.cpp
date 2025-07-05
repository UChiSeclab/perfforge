#include <bits/stdc++.h>
using namespace std;
const int inf = 10000 * 20000;
int n, w[2000], ans = inf;

// Checker functions to identify performance bottlenecks
void check_sort_invariant(int n, int sortCount) {
    if (n > 40 && sortCount > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting within nested loops!" << endl;
        abort();
    }
}

void check_loop_invariant(int n, int loopIterations) {
    if (n > 40 && loopIterations > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient loop execution!" << endl;
        abort();
    }
}

void check_combinatorial_invariant(int n, int combinationsChecked) {
    if (n > 40 && combinationsChecked > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive combinatorial operations!" << endl;
        abort();
    }
}

int main() {
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);

    int sortCount = 0;
    int loopIterations = 0;
    int combinationsChecked = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            combinationsChecked++;
            int p = w[i], q = w[j];
            w[i] = inf, w[j] = inf;
            sort(w, w + n);
            sortCount++;

            int s = 0;
            for (int k = 0; k < n; k += 2) {
                loopIterations++;
                s += w[k + 1] - w[k];
            }
            ans = min(ans, s);

            w[n - 1] = p, w[n - 2] = q;
            sort(w, w + n);
            sortCount++;
        }
    }

    // Check for performance bottlenecks at strategic points
    check_sort_invariant(n, sortCount);
    check_loop_invariant(n, loopIterations);
    check_combinatorial_invariant(n, combinationsChecked);

    cout << ans << endl;
}