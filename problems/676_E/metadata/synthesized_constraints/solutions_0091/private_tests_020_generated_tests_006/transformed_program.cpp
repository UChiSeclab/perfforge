#include <bits/stdc++.h>
const int INF = 2e9 + 7;
const long long INFLL = 1e16 + 7;
const double EPS = 1e-6;
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
int a[maxn];

void check_polynomial_evaluation_invariant(int callCount, int degree) {
    if (callCount > 200 && degree > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive polynomial evaluations!" << endl;
        abort();
    }
}

void check_large_degree_invariant(int degree, int definedCount) {
    if (degree > 90000 && definedCount > degree / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large polynomial degree with many defined coefficients!" << endl;
        abort();
    }
}

void check_loop_execution_invariant(int loopIterations, int calls) {
    if (loopIterations * calls > 100000 && loopIterations > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations in `poli` function!" << endl;
        abort();
    }
}

int poli(long long mod, int &callCount) {
    long long now = 1;
    long long ret = 0;
    int loopIterations = 0; // Track iterations for loop execution invariant
    for (int k = 0; k < n; k++) {
        ret += now * a[k];
        ret %= mod;
        now = (now * m) % mod;
        loopIterations++;
    }
    callCount++;
    check_loop_execution_invariant(loopIterations, callCount);
    if (ret) return 1;
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    n++;
    int last = -1, sum = 0;
    int definedCount = 0; // Track number of defined coefficients
    for (int k = 0; k < n; k++) {
        char tmp[100];
        scanf("%s", &tmp);
        if (tmp[0] == '?') {
            last = k & 1;
            a[k] = INF;
            sum++;
        } else {
            sscanf(tmp, "%d", &a[k]);
            definedCount++;
        }
    }

    check_large_degree_invariant(n, definedCount);

    if (m == 0) {
        if (a[0] != INF) {
            if (a[0] == 0)
                printf("Yes\n");
            else
                printf("No\n");
        } else {
            if ((n - sum) % 2)
                printf("Yes\n");
            else
                printf("No\n");
        }
        return 0;
    }

    if (last != -1) {
        if (n % 2 == 0)
            printf("Yes\n");
        else
            printf("No\n");
        return 0;
    }

    int cek = 0;
    long long ten[25];
    ten[0] = 1;
    for (int k = 1; k < 18; k++) ten[k] = ten[k - 1] * 10;

    int callCount = 0; // Initialize call count for polynomial evaluation invariant
    for (int k = 3; k < 9; k++) cek = (cek | poli(ten[k] + 7, callCount));
    cek = (cek | poli(ten[9], callCount));
    for (int k = INF; k < INF + 200; k++) cek = (cek | poli(k, callCount));

    check_polynomial_evaluation_invariant(callCount, n);

    if (cek == 0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}