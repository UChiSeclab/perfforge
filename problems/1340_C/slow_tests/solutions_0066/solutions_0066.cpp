#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using ll = long long;
using ld = long double;
constexpr ll inf = 0x3FFFFFFFFFFFFF;
struct entry {
  ll pos, full, part;
  bool operator<(const entry& o) const {
    if (full != o.full) return full > o.full;
    if (part != o.part) return part > o.part;
    return pos < o.pos;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> d(m);
  for (ll i = 0; i < m; i++) {
    cin >> d[i];
  }
  sort(begin(d), end(d));
  ll g, r;
  cin >> g >> r;
  vector<vector<ll>> res(m, vector<ll>(g, inf));
  res[0][0] = 0;
  ll offset = 0;
  deque<vector<entry>> pq;
  pq.push_back({{0, 0, 0}});
  while (!pq.empty()) {
    offset++;
    auto tmp = pq.front();
    pq.pop_front();
    for (auto e : tmp) {
      if (e.pos == m - 1) {
        if (e.part == 0) {
          e.full--;
          e.part += g;
        }
        cout << e.part + e.full * (r + g) << endl;
        return 0;
      }
      if (res[e.pos][e.part] != e.full) continue;
      for (ll px : {-1, 1}) {
        if (e.pos + px >= 0 && e.pos + px < m) {
          entry next{e.pos + px, e.full,
                     e.part + abs(d[e.pos] - d[e.pos + px])};
          if (next.part == g) {
            next.part = 0;
            next.full++;
          }
          if (next.part < g && res[next.pos][next.part] > next.full) {
            res[next.pos][next.part] = next.full;
            ll t = next.full * g + next.part - offset;
            while (pq.size() <= t) pq.resize(t + 1);
            pq[t].push_back(next);
          }
        }
      }
    }
  }
  cout << -1 << endl;
}
