#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, S = 1e6 + 5;
long long y[N], lx[N], rx[N], x[N], ly[N], ry[N];
long long ans = 1, n, m, o[S], m0, q0;
struct modification {
    long long t, p, v;
    bool operator<(const modification &oth) const { return t < oth.t; }
} mdfy[N << 1];
struct query {
    long long t, l, r;
    bool operator<(const query &oth) const { return t < oth.t; }
} qry[N << 1];
void Modify(modification &opt) {
    for (long long p = opt.p; p < S; p += p & -p) o[p] += opt.v;
}
long long Query(query &opt) {
    long long res = 0;
    for (long long p = opt.r; p; p -= p & -p) res += o[p];
    for (long long p = opt.l - 1; p; p -= p & -p) res -= o[p];
    return res;
}

// Performance bottleneck checker functions
void check_fenwick_update_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: High update frequency on Fenwick Tree!" << endl;
        abort();
    }
}

void check_boundary_density_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: High density of segments near boundaries!" << endl;
        abort();
    }
}

void check_segment_overlap_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Maximal segment overlap causing increased intersections!" << endl;
        abort();
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    
    // Check if the number of segments is high, which may lead to high update frequency
    check_fenwick_update_invariant(n + m > 150000);
    
    for (long long i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &y[i], &lx[i], &rx[i]);
        if (lx[i] == 0 && rx[i] == 1000000) ans++;
        y[i]++;
        lx[i]++;
        rx[i]++;
        mdfy[++m0] = (modification){lx[i] - 1, y[i], 1};
        mdfy[++m0] = (modification){rx[i], y[i], -1};
        
        // Check for horizontal segments near the boundaries
        check_boundary_density_invariant(lx[i] == 1 || rx[i] == S || y[i] == 1 || y[i] == S);
    }
    
    for (long long i = 1; i <= m; i++) {
        scanf("%lld %lld %lld", &x[i], &ly[i], &ry[i]);
        if (ly[i] == 0 && ry[i] == 1000000) ans++;
        x[i]++;
        ly[i]++;
        ry[i]++;
        qry[++q0] = (query){x[i], ly[i], ry[i]};
        
        // Check for vertical segments near the boundaries
        check_boundary_density_invariant(x[i] == 1 || x[i] == S || ly[i] == 1 || ry[i] == S);
    }
    
    // Check for segment overlap
    check_segment_overlap_invariant(n > 0 && m > 0);
    
    sort(mdfy + 1, mdfy + m0 + 1);
    sort(qry + 1, qry + q0 + 1);
    long long nowm = 1, nowq = 1;
    for (; nowm <= m0 && mdfy[nowm].t == 0; nowm++) Modify(mdfy[nowm]);
    for (long long t = 1; t < S; t++) {
        for (; nowq <= q0 && qry[nowq].t == t; nowq++) ans += Query(qry[nowq]);
        for (; nowm <= m0 && mdfy[nowm].t == t; nowm++) Modify(mdfy[nowm]);
    }
    printf("%lld\n", ans);
    return 0;
}