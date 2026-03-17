#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
bool Finish_read;
template <class T>
inline void read(T &x) {
  Finish_read = 0;
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    if (ch == EOF) return;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
  Finish_read = 1;
}
template <class T>
inline void print(T x) {
  if (x / 10 != 0) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar('\n');
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
}
const int maxn = 500005;
int n, k, mx;
vector<int> pos[maxn];
inline int id(int x) {
  return lower_bound(pos[k].begin(), pos[k].end(), x) - pos[k].begin();
}
inline void init() {
  read(n), read(k);
  for (int i = 1, x; i <= n; ++i) read(x), pos[x].push_back(i), mx = max(mx, x);
}
inline int calc() {
  int now = pos[k].size(), cnt = now;
  for (int i = 1; i <= mx; ++i) {
    if (!pos[i].size() || i == k) continue;
    int p = 1;
    now = max(now, cnt + p);
    for (int j = 1; j < (int)pos[i].size(); ++j)
      now = max(now,
                cnt + (p = max(p + 1 - id(pos[i][j]) + id(pos[i][j - 1]), 1)));
  }
  return now;
}
int main() { init(), writeln(calc()); }
