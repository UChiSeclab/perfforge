#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int n, a[N], buc[N], mi = inf;

void check_range_invariant(int min_value, int max_value, int n) {
    if ((max_value - min_value) > n * 10) {
        cerr << "Warning: range_invariant triggered - large range between min and max values" << endl;
        abort();
    }
}

void check_sparse_distribution_invariant(int n, const int* buc) {
    int non_zero_count = 0;
    for (int i = 0; i <= N; ++i) {
        if (buc[i] > 0) non_zero_count++;
    }
    if (non_zero_count < n / 2) {
        cerr << "Warning: sparse_distribution_invariant triggered - sparse distribution of values" << endl;
        abort();
    }
}

void check_cardinality_invariant(const int* a, int n) {
    int small_diff_count = 0;
    for (int i = 2; i <= n; ++i) {
        if (abs(a[i] - a[i - 1]) == 1) small_diff_count++;
    }
    if (small_diff_count > n * 0.8) {
        cerr << "Warning: cardinality_invariant triggered - high cardinality with small differences" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    if (n & 1) return puts("NO"), 0;
    int max_value = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mi = min(mi, a[i]);
        max_value = max(max_value, a[i]);
    }
    
    check_range_invariant(mi, max_value, n);
    
    sort(a + 1, a + 1 + n);
    
    check_cardinality_invariant(a, n);
    
    for (int i = 2; i <= n; i++)
        if (a[i] - a[i - 1] > 1) return puts("NO"), 0;
    
    for (int i = 1; i <= n; i++) ++buc[a[i] - mi + 1];
    
    check_sparse_distribution_invariant(n, buc);
    
    int u = 1;
    --buc[1];
    
    while (true) {
        if (buc[u + 1])
            --buc[++u];
        else if (buc[u - 1])
            --buc[--u];
        else
            break;
    }
    if (u != 2) return puts("NO"), 0;
    for (int i = 0; i <= N - 1; i++)
        if (buc[i]) return puts("NO"), 0;
    return puts("YES"), 0;
}