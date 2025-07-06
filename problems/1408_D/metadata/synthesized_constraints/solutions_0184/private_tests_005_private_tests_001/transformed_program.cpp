#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

// Checker function for large move index
void check_large_move_index(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large move index!" << endl;
        abort();
    }
}

// Checker function for large searchlight coordinates
void check_large_searchlight_coords(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large searchlight coordinates!" << endl;
        abort();
    }
}

template <typename T>
inline T gi() {
    register T f = 1, x = 0;
    register char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return f * x;
}

const int INF = 0x3f3f3f3f, N = 2003, M = 1000003;
int n, m;
long long ueyfgrfygds = 1000000000000000ll, kkkkkkkklslslsjdefrgr;
struct Node {
    int a, b;
} r[N], s[N];
int mx[M], mxc, mnc = INF;
int ljctrnmsl[N * N], ooooooooovovo;
pair<int, int> cccccrz[N * N], qqqqqqqqqwq[N * N];

int main() {
    n = gi<int>(), m = gi<int>();
    for (register int i = 1; i <= n; i += 1)
        r[i].a = gi<int>(), mnc = min(mnc, r[i].a), r[i].b = gi<int>();
    for (register int i = 1; i <= m; i += 1)
        s[i].a = gi<int>(), s[i].b = gi<int>();

    // Check after input, before processing that could go wrong
    check_large_searchlight_coords(*max_element(s + 1, s + m + 1, [](Node& lhs, Node& rhs) {
        return (lhs.a + lhs.b) < (rhs.a + rhs.b);
    }).a > 1000000);  // Example threshold

    ++ljctrnmsl[0];
    for (int i = 1; i <= n; i += 1)
        for (int j = 1; j <= m; j += 1) {
            int wwwwwww = max(s[j].a - r[i].a + 1, 0),
                pppppppppp = max(s[j].b - r[i].b + 1, 0);

            // Check for large move index
            check_large_move_index(wwwwwww > 1000000 || pppppppppp > 1000000);  // Example threshold

            ++ljctrnmsl[wwwwwww];
            kkkkkkkklslslsjdefrgr = max(kkkkkkkklslslsjdefrgr, 1ll * wwwwwww);
            cccccrz[++ooooooooovovo] = (make_pair)(wwwwwww, pppppppppp);
            qqqqqqqqqwq[ooooooooovovo] = (make_pair)(pppppppppp, ooooooooovovo);
        }
    ueyfgrfygds = kkkkkkkklslslsjdefrgr;
    sort(qqqqqqqqqwq + 1, qqqqqqqqqwq + 1 + ooooooooovovo);
    for (int i = 1; i <= ooooooooovovo; i += 1) {
        --ljctrnmsl[cccccrz[qqqqqqqqqwq[i].second].first];
        while (!ljctrnmsl[kkkkkkkklslslsjdefrgr]) --kkkkkkkklslslsjdefrgr;
        ueyfgrfygds =
            min(ueyfgrfygds, kkkkkkkklslslsjdefrgr + qqqqqqqqqwq[i].first);
    }
    printf("%lld\n", ueyfgrfygds);
    return 0;
}