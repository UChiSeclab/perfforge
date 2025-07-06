#include <bits/stdc++.h>
using namespace std;

int n, m, d[51], g[51][51];
bool v[51], cir;

void check_recursion_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Recursion invariant triggered - excessive depth due to sparse connectivity!" << endl;
        abort();
    }
}

void check_degree_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Degree invariant triggered - many vertices with degrees not equal to two!" << endl;
        abort();
    }
}

void check_traversal_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Traversal invariant triggered - excessive checks or redundant operations detected!" << endl;
        abort();
    }
}

void check_lexicographic_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Lexicographic invariant triggered - excessive evaluation of candidate edges!" << endl;
        abort();
    }
}

void dfs(int i) {
    if (v[i]) {
        cir = true;
        return;
    }
    v[i] = true;
    for (int j = 1; j <= n; ++j)
        if (g[i][j]) {
            g[i][j]--, g[j][i]--;
            dfs(j);
            g[i][j]++, g[j][i]++;
        }
}

bool check() {
    bool deg = true;
    for (int i = 1; i <= n; ++i) deg &= (d[i] == 2);
    
    // Check for degree invariant
    check_degree_invariant(!deg && std::count_if(d+1, d+n+1, [](int x) { return x > 2; }) > n / 2);

    if (deg) {
        memset(v, 0, sizeof(v));
        dfs(1);
        bool con = true;
        for (int i = 1; i <= n; ++i) con &= v[i];
        if (con) return true;
    }
    for (int i = 1; i <= n; ++i)
        if (d[i] > 2) return false;
    cir = false;
    for (int i = 1; i <= n; ++i) {
        memset(v, 0, sizeof(v));
        dfs(i);
    }
    if (cir) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(d, 0, sizeof(d));
    memset(g, 0, sizeof(g));
    for (int i = 0; i != m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        d[x]++, d[y]++, g[x][y]++, g[y][x]++;
    }
    
    // Check for recursion invariant
    check_recursion_invariant(n > 20 && m < n / 2);

    if (!check()) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n%d\n", n - m);
    
    for (; m < n; ++m) {
        bool flag = true;
        for (int i = 1; i <= n && flag; ++i)
            for (int j = i; j <= n && flag; ++j) {
                d[i]++, d[j]++, g[i][j]++, g[j][i]++;
                
                // Check for lexicographic invariant
                check_lexicographic_invariant(i > n / 2 && j > n / 2);

                if (check()) {
                    printf("%d %d\n", i, j);
                    flag = false;
                    break;
                }
                d[i]--, d[j]--, g[i][j]--, g[j][i]--;
            }
    }
    
    return 0;
}