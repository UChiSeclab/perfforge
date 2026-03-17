#include <bits/stdc++.h>
using namespace std;
const int N = 10;
const int inf = 1 << 29;
int d[N][N];
int loop(function<bool()> ok, function<void()> increment,
         function<void()> work) {
  return ok() ? work(), increment(), loop(ok, increment, work) : 0;
}
int main() {
  int n;
  scanf("%d", &n);
  {
    int i = 0;
    loop([&i, &n]() -> bool { return i < n; }, [&i]() { ++i; },
         [&i, &n]() {
           int j = 0;
           loop([&j, &n]() -> bool { return j < n; }, [&j]() { ++j; },
                [&i, &j]() { scanf("%d", d[i] + j); });
         });
  }
  {
    int k = 0;
    loop([&k, &n]() -> bool { return k < n; }, [&k]() { ++k; },
         [&k, &n]() {
           int i = 0;
           loop([&i, &n]() -> bool { return i < n; }, [&i]() { ++i; },
                [&k, &i, &n]() {
                  int j = 0;
                  loop([&j, &n]() -> bool { return j < n; }, [&j]() { ++j; },
                       [&k, &i, &j]() {
                         d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                       });
                });
         });
  }
  int ans = 0;
  {
    int i = 0;
    loop([&i, &n]() -> bool { return i < n; }, [&i]() { ++i; },
         [&i, &n, &ans]() {
           int j = 0;
           loop([&j, &n]() -> bool { return j < n; }, [&j]() { ++j; },
                [&i, &j, &ans]() { ans = max(ans, d[i][j]); });
         });
  }
  printf("%d\n", ans);
  return 0;
}
