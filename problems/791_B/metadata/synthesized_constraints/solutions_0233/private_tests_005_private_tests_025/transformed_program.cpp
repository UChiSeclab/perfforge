#include <bits/stdc++.h>
using namespace std;

void check_union_find_invariant(int n, int m) {
    if (n > 1000 && m < n / 10) { // Assume inefficient if very few connections
        cerr << "Warning: Union-Find inefficiency due to many isolated nodes!" << endl;
        abort();
    }
}

void check_iteration_overhead(int n, int m) {
    if (n > 1000 && m == 0) { // Large network without any connections
        cerr << "Warning: High iteration overhead due to unconnected network!" << endl;
        abort();
    }
}

void check_map_operation_invariant(const map<int, int>& mapa) {
    if (mapa.size() > 1000) { // Large number of map keys
        cerr << "Warning: Mapping operation overload due to many disconnected components!" << endl;
        abort();
    }
}

int p[150010];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
int n, m;
int cango[150010];
map<int, int> mapa;
map<int, int> mapb;

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    
    // Insert invariant checks after reading inputs
    check_union_find_invariant(n, m);
    check_iteration_overhead(n, m);
    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    
    int l, r;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &l);
        scanf("%d", &r);
        cango[l]++;
        cango[r]++;
        l = find(l);
        r = find(r);
        p[l] = r;
    }
    for (int i = 1; i <= n; i++) {
        mapb[find(i)]++;
        mapa[find(i)] += cango[i];
    }
    
    // Insert invariant check before evaluating the maps
    check_map_operation_invariant(mapa);
    
    for (auto au : mapa) {
        if (1ll * mapb[au.first] * (mapb[au.first] - 1) != au.second) {
            puts("NO");
            exit(0);
        }
    }
    puts("YES");
    return 0;
}