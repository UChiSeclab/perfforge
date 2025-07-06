#include <bits/stdc++.h>
using namespace std;

int pre[10010], ran[10010];
int mapp[1010][1010], in[1010];

// Initialize the union-find structure
void init() {
    for (int i = 0; i < 10010; i++) {
        pre[i] = i;
        ran[i] = 1;
    }
}

// Find with path compression
int findd(int a) {
    while (a != pre[a]) {
        a = pre[a];
    }
    return a;
}

// Union by rank
void unite(int a, int b) {
    int a1 = findd(a);
    int b1 = findd(b);
    if (a1 < b1) {
        pre[b1] = a1;
        ran[a1] += ran[b1];
    } else if (a1 > b1) {
        pre[a1] = b1;
        ran[b1] += ran[a1];
    }
}

// Checker implementations from Phase 3
void check_large_m_invariant(int m) {
    if (m > 900) {
        cerr << "Warning: large_m_invariant triggered - excessive iterations in nested loop due to large m" << endl;
        abort();
    }
}

void check_sparse_matrix_invariant(int m, int n) {
    if (m > 900 && n < m / 2) {
        cerr << "Warning: sparse_matrix_invariant triggered - excessive checks for sparse connections" << endl;
        abort();
    }
}

void check_redundant_connections_invariant(int m, int n) {
    if (m > 900 && n < m - 1) {
        cerr << "Warning: redundant_connections_invariant triggered - potential redundancy in connections" << endl;
        abort();
    }
}

int main() {
    int m, n, p, q;
    while (scanf("%d%d", &m, &n) == 2) {
        // Insert performance checks here after reading inputs
        check_large_m_invariant(m);
        check_sparse_matrix_invariant(m, n);
        check_redundant_connections_invariant(m, n);

        init();
        memset(mapp, 0, sizeof(mapp));
        memset(in, 0, sizeof(in));

        while (n--) {
            scanf("%d%d", &p, &q);
            mapp[p][q] = 1;
            unite(p, q);
        }

        int sum = 0, flag = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (mapp[i][j]) {
                    sum++;
                }
            }
        }

        for (int i = 1; i <= m; i++) {
            if (ran[i] == m) flag = 1;
        }

        if (sum == m - 1 && flag == 1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}