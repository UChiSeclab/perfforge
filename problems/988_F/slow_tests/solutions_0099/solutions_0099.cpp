#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
using namespace std;
const int mod = 1000000007;
const long long INF = 1e11;
struct ConvexHull {
  long long inf = 1e17;
  struct Line;
  set<Line> hull;
  bool hasNext(set<Line>::iterator it) {
    return (it != hull.end()) && (next(it) != hull.end());
  }
  bool hasPrev(set<Line>::iterator it) {
    return (it != hull.end()) && (it != hull.begin());
  }
  double getIntersection(set<Line>::iterator a, set<Line>::iterator b) {
    if (a->k == b->k) return (double)inf;
    return (double)(a->b - b->b) / (double)(b->k - a->k);
  }
  bool isBad(set<Line>::iterator a, set<Line>::iterator b,
             set<Line>::iterator c) {
    return getIntersection(a, c) <= getIntersection(a, b);
  }
  bool isBad(set<Line>::iterator it) {
    return hasPrev(it) && hasNext(it) && isBad(prev(it), it, next(it));
  }
  set<Line>::iterator updateBorder(set<Line>::iterator it) {
    Line tmp = *it;
    if (hasNext(it))
      tmp.intersection = getIntersection(it, next(it));
    else
      tmp.intersection = inf;
    it = hull.erase(it);
    it = hull.insert(it, tmp);
    return it;
  }
  void addLine(long long k, long long b) {
    Line cur(k, b);
    set<Line>::iterator it = hull.lower_bound(cur);
    if ((it != hull.end()) && (it->k == k)) {
      if (it->b > b)
        it = hull.erase(it);
      else
        return;
    }
    it = hull.insert(it, cur);
    if (isBad(it)) {
      hull.erase(it);
      return;
    }
    while (hasPrev(it) && isBad(prev(it))) hull.erase(prev(it));
    while (hasNext(it) && isBad(next(it))) hull.erase(next(it));
    it = updateBorder(it);
    if (hasNext(it)) updateBorder(next(it));
    if (hasPrev(it)) updateBorder(prev(it));
  }
  long long query(long long x) {
    Line tmp(0, 0, 1, x);
    set<Line>::iterator result = hull.lower_bound(tmp);
    if (result == hull.end()) return inf;
    return result->f(x);
  }
  struct Line {
    long long k, b;
    double intersection;
    bool isQuery;
    Line() {}
    Line(long long k, long long b, bool isQuery = 0, double intersection = 0) {
      this->k = k;
      this->b = b;
      this->isQuery = isQuery;
      this->intersection = intersection;
    }
    bool operator<(const Line &another) const {
      if (isQuery || another.isQuery)
        return intersection < another.intersection;
      return k > another.k;
    }
    long long f(long long x) const { return k * x + b; }
  };
};
int a, n, m, rain[2005];
long long dp[2005], mn[2005];
ConvexHull CHT;
int main() {
  long long x, p, l, r;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
    rain[l + 1]++;
    rain[r + 1]--;
  }
  for (int i = 1; i <= a; i++) rain[i] += rain[i - 1];
  fill(mn, mn + 2005, INF);
  for (int i = 1; i <= m; i++) {
    cin >> x >> p;
    mn[x] = min(mn[x], p);
  }
  for (int i = 0; i <= a; i++) {
    if (i) dp[i] = dp[i - 1];
    if (rain[i]) dp[i] = CHT.query(i);
    CHT.addLine(mn[i], dp[i] - mn[i] * i);
  }
  if (dp[a] > 10000000000LL)
    cout << "-1";
  else
    cout << dp[a];
  cout << "\n"
       << "\n";
  return 0;
}
