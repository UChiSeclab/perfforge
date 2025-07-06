#include <bits/stdc++.h>
using namespace std;
const int inf = 1010101010;

// Checkers integrated into the program
void check_large_range_invariant(int mx, int mi) {
    if (mx - mi > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - large range after adjustment!" << endl;
        abort();
    }
}

void check_excessive_iterations_invariant(int mx) {
    if (mx > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations due to broad range!" << endl;
        abort();
    }
}

void check_dense_distribution_invariant(const vector<int>& cnt, int mx) {
    int dense_threshold = 100;
    int dense_count = 0;
    for (int i = 0; i <= mx; ++i) {
        if (cnt[i] > 0) {
            dense_count++;
        }
    }
    if (dense_count > dense_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - dense value distribution!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < (n); i++) cin >> v[i];
    int mi = inf, mx = 0;
    for (int i = 0; i < (n); i++) mi = min(mi, v[i]), mx = max(mx, v[i]);
    
    // Checking the first invariant (large range)
    check_large_range_invariant(mx, mi);

    // Adjusting all numbers by subtracting the minimum value
    for (int i = 0; i < (n); i++) v[i] -= mi;
    mx -= mi;
    vector<int> cnt(100005);
    for (int i = 0; i < (n); i++) cnt[v[i]]++;
    
    // Checking the second and third invariants (excessive iterations and dense distribution)
    check_excessive_iterations_invariant(mx);
    check_dense_distribution_invariant(cnt, mx);

    int nd = 0;
    for (int i = mx - 1; i > 0; i--) {
        if (cnt[i] == 0) {
            puts("NO");
            return 0;
        }
        cnt[i]--;
        nd++;
    }
    for (int curpos = 0; curpos != mx + 1;) {
        if (cnt[curpos] == 0) {
            puts("NO");
            return 0;
        }
        cnt[curpos]--;
        nd++;
        if (curpos > 0 && cnt[curpos - 1]) {
            curpos--;
        } else {
            curpos++;
        }
    }
    if (nd == n)
        puts("YES");
    else {
        puts("NO");
        return 0;
    }
}