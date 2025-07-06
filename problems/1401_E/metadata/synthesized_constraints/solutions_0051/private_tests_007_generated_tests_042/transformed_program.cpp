#include <bits/stdc++.h>
using namespace std;
const long long N = 100010, M = 1000010;
long long n, m, ans = 1, sum[M];
struct Segment {
  long long t, p, val;
} seg[N << 1];
struct Query {
  long long t, l, r;
} que[N << 1];
inline long long read() {
  long long x = 0, tmp = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') tmp = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return tmp * x;
}
inline long long lowbit(long long x) { return x & (-x); }
inline void update(Segment p) {
  for (long long i = p.p; i < M; i += lowbit(i)) sum[i] += p.val;
}
inline long long query(Query p) {
  long long ans = 0;
  for (long long i = p.r; i; i -= lowbit(i)) ans += sum[i];
  for (long long i = p.l - 1; i; i -= lowbit(i)) ans -= sum[i];
  return ans;
}
inline bool cmp_seg(Segment a, Segment b) { return a.t < b.t; }
inline bool cmp_que(Query a, Query b) { return a.t < b.t; }

// Checker function for segment spanning
void check_segment_span(long long lx, long long rx) {
    if (lx == 1 && rx == 1000001) {
        cerr << "Warning: Performance bottleneck condition triggered due to segment spanning the entire width!" << endl;
        abort();
    }
}

// Checker function for high volume of updates
void check_high_volume_updates(long long n, long long m) {
    if (n > 10000 || m > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high volume of segments!" << endl;
        abort();
    }
}

int main() {
  n = read();
  m = read();
  
  // Check for high volume of updates
  check_high_volume_updates(n, m);
  
  for (long long i = 1; i <= n; i++) {
    long long y = read() + 1, lx = read() + 1, rx = read() + 1;
    // Check if any horizontal segment spans the entire width
    check_segment_span(lx, rx);
    if (lx == 1 && rx == 1000001) ans++;
    seg[i * 2 - 1] = Segment{lx - 1, y, 1};
    seg[i * 2] = Segment{rx, y, -1};
  }
  for (long long i = 1; i <= m; i++) {
    long long x = read() + 1, ly = read() + 1, ry = read() + 1;
    if (ly == 1 && ry == 1000001) ans++;
    que[i] = Query{x, ly, ry};
  }
  sort(seg + 1, seg + 1 + n * 2, cmp_seg);
  sort(que + 1, que + 1 + m, cmp_que);
  long long now_seg = 1, now_que = 1;
  for (; now_seg <= n * 2 && seg[now_seg].t == 0; now_seg++)
    update(seg[now_seg]);
  for (long long i = 1; i < M; i++) {
    for (; now_que <= m && que[now_que].t == i; now_que++)
      ans += query(que[now_que]);
    for (; now_seg <= n * 2 && seg[now_seg].t == i; now_seg++)
      update(seg[now_seg]);
  }
  cout << ans << endl;
  return 0;
}