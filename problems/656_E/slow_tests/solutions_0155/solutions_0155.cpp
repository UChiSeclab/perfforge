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
    loop([&]() -> bool { return i < n; }, [&]() { ++i; },
         [&]() {
           int j = 0;
           loop([&]() -> bool { return j < n; }, [&]() { ++j; },
                [&]() { scanf("%d", d[i] + j); });
         });
  }
  {
    int k = 0;
    loop([&]() -> bool { return k < n; }, [&]() { ++k; },
         [&]() {
           int i = 0;
           loop([&]() -> bool { return i < n; }, [&]() { ++i; },
                [&]() {
                  int j = 0;
                  loop([&]() -> bool { return j < n; }, [&]() { ++j; },
                       [&]() { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); });
                });
         });
  }
  int ans = 0;
  {
    int i = 0;
    loop([&]() -> bool { return i < n; }, [&]() { ++i; },
         [&]() {
           int j = 0;
           loop([&]() -> bool { return j < n; }, [&]() { ++j; },
                [&]() { ans = max(ans, d[i][j]); });
         });
  }
  printf("%d\n", ans);
  return 0;
}
