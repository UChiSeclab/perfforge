#include <bits/stdc++.h>
using namespace std;

int hbb[109], hgg[109];

void check_loop_execution_invariant(int hb, int hg, int n, int m) {
    if (hb < n && hg < m) {
        cerr << "Warning: Potential for excessive loop iterations due to incomplete initial happiness distribution!" << endl;
        abort();
    }
}

void check_interaction_invariant(int hb, int hg, int n, int m) {
    if (hb + hg < n + m) {
        cerr << "Warning: Insufficient initial happy connections may lead to prolonged execution!" << endl;
        abort();
    }
}

void check_modulo_operation_invariant(int i, int n, int m) {
    if (i % n == 0 && i % m == 0) {
        cerr << "Warning: Modulo pattern may lead to inefficient propagation!" << endl;
        abort();
    }
}

int main() {
    int n, m, a, b, hb, hg, i;
    scanf("%d %d", &n, &m);
    scanf("%d", &hb);
    memset(hbb, 0, sizeof(hbb));
    for (i = 0; i < hb; i++) {
        scanf("%d", &a);
        hbb[a] = 1;
    }
    scanf("%d", &hg);
    memset(hgg, 0, sizeof(hgg));
    for (i = 0; i < hg; i++) {
        scanf("%d", &a);
        hgg[a] = 1;
    }

    // Insert checks before the loop begins
    check_loop_execution_invariant(hb, hg, n, m);
    check_interaction_invariant(hb, hg, n, m);

    int flag = 1;
    for (i = 0; i <= 1000000; i++) {
        // Insert check for potential inefficient modulo operation
        check_modulo_operation_invariant(i, n, m);

        if (hg == m && hb == n) {
            flag = 0;
            break;
        }
        a = i % n;
        b = i % m;
        if (hbb[a]) {
            if (hgg[b] == 0) {
                hgg[b] = 1;
                hg++;
            }
        } else if (hgg[b]) {
            if (hbb[a] == 0) {
                hbb[a] = 1;
                hb++;
            }
        }
    }
    printf("%s\n", flag ? "No" : "Yes");
    return 0;
}