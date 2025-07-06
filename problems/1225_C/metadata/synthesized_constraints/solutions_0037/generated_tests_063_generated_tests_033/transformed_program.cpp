#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 2;
const int MAXM = 1e5 + 10;

long long inline in() {
    long long x = 0, flag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * flag;
}

void check_excessive_iterations(long long i, long long m, long long n) {
    if (i * m >= n) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations in outer loop!" << endl;
        abort();
    }
}

void check_high_inner_iterations(long long now, int j) {
    if (now > 0 && j <= 0) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count in inner loop!" << endl;
        abort();
    }
}

void check_unproductive_iterations(long long now, long long p_j) {
    if (p_j > now) {
        cerr << "Warning: Performance bottleneck condition triggered - unproductive iterations in inner loop!" << endl;
        abort();
    }
}

int head[MAXN], nume;
struct Adj {
    int nex, to, w;
} adj[MAXM << 1];

void addedge(int from, int to, int w) {
    adj[++nume] = (Adj){head[from], to, w};
    head[from] = nume;
}

void link(int u, int v, int w) {
    addedge(u, v, w);
    addedge(v, u, w);
}

long long n, m;
long long p[60];

int main() {
    n = in();
    m = in();
    p[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        p[i] = p[i - 1] * 2;
    }
    long long ans = 1e18;
    for (long long i = 1; i <= 1000000; ++i) {
        long long now = n - i * m;
        check_excessive_iterations(i, m, n);  // Check for excessive iterations

        long long need = 0, needm = 0;
        for (int j = 50; j >= 0; --j) {
            check_high_inner_iterations(now, j);  // Check for high iterations in the inner loop

            if (p[j] > now) {
                check_unproductive_iterations(now, p[j]);  // Check for unproductive iterations
                continue;
            }
            ++need;
            now -= p[j];
            needm += p[j];
        }
        if (now != 0) continue;
        if (need <= i && i <= needm) {
            ans = min(ans, i);
            break;
        }
    }
    if (ans == 1000000000000000000)
        printf("-1");
    else
        printf("%lld\n", ans);
    return 0;
}