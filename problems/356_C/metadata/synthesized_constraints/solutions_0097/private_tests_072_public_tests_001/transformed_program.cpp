#include <bits/stdc++.h>
using namespace std;
int N;
int Ai[1000010];
int F[5], E[5];

void check_large_n_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck due to large 'n' causing excessive loop iterations!" << endl;
        abort();
    }
}

void check_sorting_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck due to sorting a large array!" << endl;
        abort();
    }
}

void check_frequent_recalc_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck due to frequent recalculations in the loop!" << endl;
        abort();
    }
}

void check_imbalance_invariant(int F[], int n) {
    int imbalance = F[1] + F[2];
    if (imbalance > n / 2) {
        cerr << "Warning: Performance bottleneck due to imbalance in compartments!" << endl;
        abort();
    }
}

void read();
void solve();

int main() {
    read();
    solve();
    return 0;
}

void read() {
    cin >> N;
    check_large_n_invariant(N);  // Check for large 'n' before processing
    for (int i = 0; i < N; ++i) cin >> Ai[i];
}

void solve() {
    int sum = accumulate(&Ai[0], &Ai[N], 0), res = sum;
    check_sorting_invariant(N);  // Check before sorting
    stable_sort(&Ai[0], &Ai[N]);
    for (int i = 0; i < N; ++i) ++F[Ai[i]];
    check_imbalance_invariant(F, N);  // Check for imbalances after frequency calculation
    for (int i = 0; i < N; ++i) {
        check_frequent_recalc_invariant(N);  // Check before entering recalculations within loops
        int ereq = E[1] + 2 * E[2] + 3 * E[3] + 4 * E[4];
        int favl = F[4];
        int freq = 2 * F[1] + F[2];
        int ftsp = 3 * F[1] + 2 * F[2] + F[3];
        if (ftsp >= ereq && ereq + favl >= freq) res = min(res, max(freq, ereq));
        --F[Ai[i]], ++E[Ai[i]];
    }
    cout << (res < sum ? res : -1) << "\n";
}