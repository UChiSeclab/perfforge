#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m;
int B_h[maxn];
int G_h[maxn];

void check_max_people_invariant(int n, int m, int happyBoysCount, int happyGirlsCount) {
    if (n == 100 && m == 100 && happyBoysCount == happyGirlsCount) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum people with balanced happiness!" << endl;
        abort();
    }
}

void check_slow_propagation_invariant(int sb, int sg, int n, int m) {
    if (sb < n / 2 && sg < m / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - slow happiness propagation due to isolated groups!" << endl;
        abort();
    }
}

int main() {
    int i, j;
    while (scanf("%d%d", &n, &m) != EOF) {
        int x, y;
        int a, b;
        memset(B_h, 0, sizeof(B_h));
        memset(G_h, 0, sizeof(G_h));
        scanf("%d", &x);
        for (i = 0; i < x; i++) {
            scanf("%d", &a);
            B_h[a] = 1;
        }
        scanf("%d", &y);
        for (i = 0; i < y; i++) {
            scanf("%d", &b);
            G_h[b] = 1;
        }

        // Check for maximum people invariant after reading input
        check_max_people_invariant(n, m, x, y);

        int ans = 100000;
        int k = 0;
        int flag = 0;
        while (ans--) {
            int boy = (k) % n;
            int gir = (k) % m;
            if (B_h[boy] || G_h[gir]) {
                B_h[boy] = 1;
                G_h[gir] = 1;
            }
            k++;
            int sb = 0, sg = 0;
            for (i = 0; i < n; i++) {
                if (B_h[i]) sb++;
            }
            for (i = 0; i < m; i++) {
                if (G_h[i]) sg++;
            }

            // Check for slow propagation invariant during each iteration
            check_slow_propagation_invariant(sb, sg, n, m);

            if (sb == n && sg == m) {
                flag = 1;
                break;
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}