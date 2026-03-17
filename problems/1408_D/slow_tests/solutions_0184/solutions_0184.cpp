#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
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
  ++ljctrnmsl[0];
  for (int i = 1; i <= n; i += 1)
    for (int j = 1; j <= m; j += 1) {
      int wwwwwww = max(s[j].a - r[i].a + 1, 0),
          pppppppppp = max(s[j].b - r[i].b + 1, 0);
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
