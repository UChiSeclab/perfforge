#include <bits/stdc++.h>
using namespace std;

void fastio() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct rec {
    long long flg;
    long long end;
};

void check_large_timespan_invariant(long long t, long long max_t, int n) {
    if (t > max_t * 10 && n > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - large time span with high task time requirement!" << endl;
        abort();
    }
}

void check_server_utilization_invariant(int n, long long servcnt) {
    if (servcnt < n / 2 && n > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - high server utilization with a large number of servers!" << endl;
        abort();
    }
}

void check_repeated_updates_invariant(long long t, int n) {
    if (t > 100000 && n > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated server status updates over large time!" << endl;
        abort();
    }
}

int main() {
    fastio();
    long long i, j, n, q;
    cin >> n >> q;
    struct rec serv[n + 1];
    long long arry[q][3];
    for (i = 0; i < q; i++) cin >> arry[i][0] >> arry[i][1] >> arry[i][2];
    for (i = 0; i < n + 1; i++) {
        serv[i].flg = 0;
        serv[i].end = -5;
    }
    long long t = 0;
    long long k = 0;
    long long servcnt = n;
    
    // Check invariants before starting the main loop
    check_large_timespan_invariant(arry[q-1][0], 100000, n);
    
    while (k != q) {
        t++;
        check_repeated_updates_invariant(t, n);
        for (i = 1; i < n + 1; i++) {
            if (serv[i].end == t) {
                serv[i].flg = 0;
                serv[i].end = -5;
                servcnt++;
            }
        }
        if (t == arry[k][0]) {
            check_server_utilization_invariant(n, servcnt);
            if (servcnt < arry[k][1]) {
                cout << -1 << endl;
                k++;
            } else {
                long long scnt = arry[k][1];
                long long ans = 0;
                for (i = 1; i < n + 1; i++) {
                    if (serv[i].flg == 0) {
                        serv[i].flg = 1;
                        serv[i].end = arry[k][2] + t;
                        ans += i;
                        scnt--;
                        if (scnt == 0) {
                            break;
                        }
                    }
                }
                cout << ans << endl;
                servcnt -= arry[k][1];
                k++;
            }
        }
    }
    return 0;
}