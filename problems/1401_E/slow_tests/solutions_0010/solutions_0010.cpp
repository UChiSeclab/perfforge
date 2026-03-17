#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
inline long long int GCD(long long int x, long long int y) {
  if (x < y) swap(x, y);
  if (x == 0) return y;
  if (y == 0) return x;
  return GCD(x % y, y);
}
long long int phi(long long int n) {
  long long int result = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
long long int power(long long int x, long long int n, long long int mod) {
  long long int res = 1;
  x %= mod;
  while (n) {
    if (n & 1) {
      res = ((res * x) % mod + mod) % mod;
    }
    x = ((x * x) % mod + mod) % mod;
    n >>= 1;
  }
  return res;
}
long long int N, M;
const int MAXN = 1500010;
long long int tree[4 * MAXN] = {0};
void build(long long int node, long long int start, long long int end) {
  if (start == end) {
    tree[node] = 0;
  } else {
    long long int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = 0;
  }
}
void clear() { build(1, 0, 1000000); }
void update(long long int node, long long int start, long long int end,
            long long int l, long long int r, long long int val) {
  if (start > end || l > end || r < start) return;
  if (l <= start && end <= r) {
    tree[node]++;
    return;
  }
  long long int mid = (start + end) / 2;
  if (l <= mid) update(2 * node, start, mid, l, r, val);
  if (mid + 1 <= r) update(2 * node + 1, mid + 1, end, l, r, val);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long int query(long long int node, long long int start, long long int end,
                    long long int l, long long int r) {
  if (start > end || l > end || r < start) return 0;
  if (l <= start && end <= r) {
    return tree[node];
  }
  long long int mid = (start + end) / 2;
  long long int lft = 0, rght = 0;
  if (l <= mid) lft = query(2 * node, start, mid, l, r);
  if (mid + 1 <= r) rght = query(2 * node + 1, mid + 1, end, l, r);
  return lft + rght;
}
inline bool myfun(const pair<long long int, long long int> &a,
                  const pair<long long int, long long int> &b) {
  if (a.second > b.second)
    return true;
  else if (a.second == b.second) {
    if (a.first <= b.first) return true;
  }
  return false;
}
inline bool myfun2(const pair<long long int, long long int> &a,
                   const pair<long long int, long long int> &b) {
  if (a.second < b.second)
    return true;
  else if (a.second == b.second) {
    if (a.first <= b.first) return true;
  }
  return false;
}
vector<pair<long long int, long long int> > up, down;
long long int lft[MAXN] = {0}, rght[MAXN] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> N >> M;
  for (long long int i = 0; i < MAXN; i++) {
    lft[i] = -1;
    rght[i] = -1;
  }
  long long int y, x, l, r;
  long long int pooreh = 0, poorev = 0;
  for (long long int i = 1; i <= N; i++) {
    cin >> y >> l >> r;
    if (l == 0 && r == 1000000) {
      pooreh++;
      lft[y] = r;
      continue;
    }
    if (l == 0) {
      lft[y] = r;
    }
    if (r == 1000000) {
      rght[y] = l;
    }
  }
  for (long long int i = 1; i <= M; i++) {
    cin >> x >> l >> r;
    if (l == 0 && r == 1000000) {
      up.push_back(make_pair(x, l));
      poorev++;
      continue;
    }
    if (l == 0) {
      down.push_back(make_pair(x, r));
    }
    if (r == 1000000) {
      up.push_back(make_pair(x, l));
    }
  }
  if (N == 0) {
    cout << 1 + poorev << endl;
    return 0;
  }
  if (M == 0) {
    cout << 1 + pooreh << endl;
    return 0;
  }
  long long int ans = 1;
  sort(up.begin(), up.end(), myfun);
  sort(down.begin(), down.end(), myfun2);
  long long int indx = 1000000;
  for (long long int i = 0; i < up.size(); i++) {
    x = up[i].first, l = up[i].second;
    ;
    if (indx >= 0) {
      while (indx >= 0 && indx >= l) {
        if (lft[indx] != -1) {
          update(1, 0, 1000000, lft[indx], lft[indx], 1);
        }
        indx--;
      }
    }
    ans += query(1, 0, 1000000, x, 1000000);
  };
  clear();
  indx = 1000000;
  for (long long int i = 0; i < up.size(); i++) {
    x = up[i].first, l = up[i].second;
    ;
    if (indx >= 0) {
      while (indx >= 0 && indx >= l) {
        if (rght[indx] != -1) {
          update(1, 0, 1000000, rght[indx], rght[indx], 1);
        }
        indx--;
      }
    }
    ans += query(1, 0, 1000000, 0, x);
  };
  clear();
  indx = 0;
  for (long long int i = 0; i < down.size(); i++) {
    x = down[i].first, r = down[i].second;
    ;
    if (indx <= 1000000) {
      while (indx <= 1000000 && indx <= r) {
        if (lft[indx] != -1) update(1, 0, 1000000, lft[indx], lft[indx], 1);
        indx++;
      }
    }
    ans += query(1, 0, 1000000, x, 1000000);
  };
  clear();
  indx = 0;
  for (long long int i = 0; i < down.size(); i++) {
    x = down[i].first, r = down[i].second;
    ;
    if (indx <= 1000000) {
      while (indx <= 1000000 && indx <= r) {
        if (rght[indx] != -1) {
          update(1, 0, 1000000, rght[indx], rght[indx], 1);
        }
        indx++;
      }
    }
    ans += query(1, 0, 1000000, 0, x);
  };
  cout << ans + pooreh + poorev << endl;
}
