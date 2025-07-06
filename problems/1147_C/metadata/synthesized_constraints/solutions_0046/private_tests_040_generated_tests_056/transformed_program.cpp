#include <bits/stdc++.h>
using namespace std;

template <typename T = long long>
inline T read() {
    T s = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        s = (s << 3) + (s << 1) + ch - 48;
        ch = getchar();
    }
    return s * f;
}

const int N = 1e5 + 5, M = 1e6 + 5, MOD = 1e9 + 7, CM = 998244353,
          INF = 0x3f3f3f3f;
const long long linf = 0x7f7f7f7f7f7f7f7f;
int a[N];

void check_repeated_set_insertions(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated set insertions!" << endl;
        abort();
    }
}

void check_minimal_value_reductions(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive minimal value reductions!" << endl;
        abort();
    }
}

void check_non_trivial_configurations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - non-trivial configurations!" << endl;
        abort();
    }
}

void check_loop_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop complexity!" << endl;
        abort();
    }
}

void solve(int kase) {
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int k = n / 2;
    int who = 0;

    while (1) {
        set<int> ss;
        for (int i = 1; i <= n; i++) ss.insert(a[i]);

        // Check for repeated set insertions
        check_repeated_set_insertions(ss.size() < n / 2);

        if (ss.size() == 1) {
            break;
        }
        who = 1 - who;
        int mi = INF;
        for (int i = 1; i <= n; i++) mi = min(mi, a[i]);

        // Check for minimal value reductions
        check_minimal_value_reductions(mi > 0 && count(a + 1, a + n + 1, mi) > n / 2);

        int tot = 0, num = 0;
        for (int i = 1; i <= n; i++) tot += a[i] == mi, num += a[i] != 0;

        if (tot == n / 2) {
            break;
        }
        if (num == n / 2) {
            break;
        }
        if (num < n / 2) {
            who = 1 - who;
            break;
        }
        if (tot < n / 2) {
            for (int i = 1, j = 0; i <= n && j <= k; i++) {
                if (a[i] != mi) a[i] = mi, j++;
            }
        } else {
            if (mi == 0) {
                who = 1 - who;
                break;
            }
            int now = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == mi) {
                    now++;
                    a[i]--;
                    break;
                }
            }
            std::vector<int> vis(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                if (now >= k) break;
                if (a[i] > mi) {
                    now++;
                    a[i]--;
                    vis[i] = 1;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (now >= k) break;
                if (a[i] == mi && vis[i] != 0) {
                    now++;
                    a[i]--;
                }
            }
        }

        // Check for non-trivial configurations
        check_non_trivial_configurations(num > n / 2 && tot < n / 2);

        // Check for loop complexity
        check_loop_complexity((tot + num) > (n * 0.75));
    }
    printf("%s\n", who ? "Alice" : "Bob");
}

const bool ISFILE = 0, DUO = 0;

int main() {
    clock_t start, finish;
    double totaltime;
    start = clock();
    if (ISFILE) freopen("/Users/i/Desktop/practice/in.txt", "r", stdin);
    if (DUO) {
        int Kase = 0;
        cin >> Kase;
        for (int kase = 1; kase <= Kase; kase++) solve(kase);
    } else
        solve(1);
    finish = clock();
    return 0;
}