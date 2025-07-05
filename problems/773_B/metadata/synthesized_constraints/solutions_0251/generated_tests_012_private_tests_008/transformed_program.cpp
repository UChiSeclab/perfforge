#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

struct node {
    long long a, b, c, d, e;
} pp[1000003];

long long A, B, C, D, E;
const long long p[] = {-1, 1, 1, 1, 1, 1, 1};
const long long q[] = {1, 32, 16, 8, 4, 2, 1};
long long t[13];

namespace solve {
    bool cmp(long long x, long long y, long long z, long long w) {
        if (z == -1) return 0;
        return x * w < y * z;
    }
    bool ccmp(long long x, long long y, long long z, long long w) {
        if (z == -1) return 0;
        return x * w <= y * z;
    }
    long long qwq(long long l, long long r, long long n, long long op) {
        if (op == 0)
            if (ccmp(r, n, p[op], q[op]) || cmp(p[op + 1], q[op + 1], l, n)) return 0;
        if (op != 0)
            if (ccmp(r, n, p[op], q[op]) || cmp(p[op + 1], q[op + 1], l, n)) return 0;
        return 1;
    }
}

const long long s[] = {3000, 2500, 2000, 1500, 1000, 500};

void check_nested_loop_explosion(long long t0, long long t1, long long t2, long long t3, long long t4) {
    if (t0 * t1 * t2 * t3 * t4 > 10000) { // Example threshold for detecting excessive permutations
        cerr << "Warning: Nested loop explosion detected!" << endl;
        abort();
    }
}

void check_complex_condition_use(long long qwq_calls) {
    if (qwq_calls > 1000000) { // Threshold for excessive calls to qwq function
        cerr << "Warning: High complexity in condition checking detected!" << endl;
        abort();
    }
}

void check_problem_score_threshold(long long A, long long B, long long C, long long D, long long E, long long n) {
    if ((A > 100 || B > 100 || C > 100 || D > 100 || E > 100) && n >= 120) {
        cerr << "Warning: Problem score threshold complexity detected!" << endl;
        abort();
    }
}

signed main() {
    long long n = read();
    for (long long i = 1; i <= n; i++) {
        pp[i].a = read(), pp[i].b = read(), pp[i].c = read(), pp[i].d = read(), pp[i].e = read();
        if (pp[i].a != -1) ++A;
        if (pp[i].b != -1) ++B;
        if (pp[i].c != -1) ++C;
        if (pp[i].d != -1) ++D;
        if (pp[i].e != -1) ++E;
    }

    check_problem_score_threshold(A, B, C, D, E, n); // Check for problem score thresholds

    long long ans = 1000000008;
    long long qwq_calls = 0; // Track calls to qwq function

    for (t[0] = 0; t[0] < 6; t[0]++)
        for (t[1] = 0; t[1] < 6; t[1]++)
            for (t[2] = 0; t[2] < 6; t[2]++)
                for (t[3] = 0; t[3] < 6; t[3]++)
                    for (t[4] = 0; t[4] < 6; t[4]++) {
                        long long d = 0;
                        if (pp[1].a != -1) d += s[t[0]] - s[t[0]] / 250 * pp[1].a;
                        if (pp[1].b != -1) d += s[t[1]] - s[t[1]] / 250 * pp[1].b;
                        if (pp[1].c != -1) d += s[t[2]] - s[t[2]] / 250 * pp[1].c;
                        if (pp[1].d != -1) d += s[t[3]] - s[t[3]] / 250 * pp[1].d;
                        if (pp[1].e != -1) d += s[t[4]] - s[t[4]] / 250 * pp[1].e;
                        if (pp[2].a != -1) d -= s[t[0]] - s[t[0]] / 250 * pp[2].a;
                        if (pp[2].b != -1) d -= s[t[1]] - s[t[1]] / 250 * pp[2].b;
                        if (pp[2].c != -1) d -= s[t[2]] - s[t[2]] / 250 * pp[2].c;
                        if (pp[2].d != -1) d -= s[t[3]] - s[t[3]] / 250 * pp[2].d;
                        if (pp[2].e != -1) d -= s[t[4]] - s[t[4]] / 250 * pp[2].e;
                        if (d > 0) {
                            for (long long j = 0; j <= 4000; ++j) {
                                long long f = 0;
                                if (solve::qwq(A, A + (j * (pp[1].a != -1)), n + j, t[0])) ++f;
                                if (solve::qwq(B, B + (j * (pp[1].b != -1)), n + j, t[1])) ++f;
                                if (solve::qwq(C, C + (j * (pp[1].c != -1)), n + j, t[2])) ++f;
                                if (solve::qwq(D, D + (j * (pp[1].d != -1)), n + j, t[3])) ++f;
                                if (solve::qwq(E, E + (j * (pp[1].e != -1)), n + j, t[4])) ++f;
                                qwq_calls += 5; // Count each call to qwq
                                if (f == 5) {
                                    ans = min(ans, j);
                                    break;
                                }
                            }
                        }
                        check_nested_loop_explosion(t[0], t[1], t[2], t[3], t[4]); // Check nested loop explosion
                    }

    check_complex_condition_use(qwq_calls); // Check for high complexity in condition checking

    if (ans == 1000000008)
        puts("-1");
    else
        printf("%lld\n", ans);

    return 0;
}