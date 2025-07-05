#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance-characterizing invariants
void check_segment_tree_size_invariant(int n, int k) {
    if (n > 90000 && k > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large segment tree with many operations!" << endl;
        abort();
    }
}

void check_high_cost_queries_invariant(int k, int n) {
    if (k == n - 1) {
        cerr << "Warning: Performance bottleneck condition triggered - high query operation cost due to k nearly equal to n!" << endl;
        abort();
    }
}

void check_repeated_updates_invariant(int n) {
    if (n > 90000) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated updates in critical loops!" << endl;
        abort();
    }
}

int k, n;
long long b;
long long a[100005];
pair<long long, int> r[100005];
long long ar[100005];
int tree_n;
pair<int, long long> tree[300005];

void init(int n1) {
    tree_n = 1;
    while (tree_n < n1) {
        tree_n *= 2;
    }
    for (int i = 0; i <= 2 * tree_n; i++) {
        tree[i] = make_pair(0, 0);
    }
}

void update(int po) {
    int upd = r[po].first;
    po += tree_n - 1;
    tree[po] = make_pair(1, upd);
    while (po > 1) {
        po = po / 2;
        tree[po].first = tree[po * 2].first + tree[po * 2 + 1].first;
        tree[po].second = tree[po * 2].second + tree[po * 2 + 1].second;
    }
}

void update1(int po) {
    int upd = r[po].first;
    po += tree_n - 1;
    tree[po] = make_pair(0, 0);
    while (po > 1) {
        po = po / 2;
        tree[po].first = tree[po * 2].first + tree[po * 2 + 1].first;
        tree[po].second = tree[po * 2].second + tree[po * 2 + 1].second;
    }
}

long long query(int po, int op) {
    if (op == 0) return 0;
    if (op >= tree[po].first) return tree[po].second;
    if (op <= tree[2 * po + 1].first) return query(po * 2 + 1, op);
    return query(po * 2 + 1, tree[2 * po + 1].first) +
           query(po * 2, op - tree[2 * po + 1].first);
}

int main() {
    scanf("%d %d", &n, &k);
    scanf("%I64d", &b);
    
    // Insert performance checks
    check_segment_tree_size_invariant(n, k);
    check_high_cost_queries_invariant(k, n);
    check_repeated_updates_invariant(n);

    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        r[i].first = a[i], r[i].second = i;
    }
    init(n);
    sort(r + 1, r + n + 1);
    for (int i = n; i >= 1; i--) ar[r[i].second] = i;
    for (int i = 1; i < n; i++) {
        update(ar[i]);
    }
    for (int i = 1; i < n; i++) {
        update1(ar[i]);
        long long chk = a[i] + query(1, k - 1);
        if (chk > b) {
            printf("%d", i);
            return 0;
        }
        update(ar[i]);
    }
    printf("%d", n);
    return 0;
}