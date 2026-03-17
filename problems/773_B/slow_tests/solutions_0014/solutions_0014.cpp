#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
const long long MOD = 1000000000 + 7;
const long long MAGIC = 123123123;
const double PI = 4 * atan(1.);
const double EPS = 1E-7;
void time_elapsed() {
  cout << "\nTIME ELAPSED: " << (double)clock() / CLOCKS_PER_SEC << " sec\n";
}
struct frac;
template <typename T>
T gcd(T a, T b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
template <class T>
T gcd(T a, T b, T& x, T& y) {
  if (!a) {
    x = 0, y = 1;
    return b;
  }
  T x1, y1;
  T d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
template <typename T>
T lcm(T a, T b) {
  return (a / gcd(a, b)) * b;
}
template <typename T, typename M>
T neg_mod(T a, M mod) {
  return ((a % mod) + mod) % mod;
}
long long binpow(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
long long binpow_mod(long long x, long long p, long long m) {
  long long res = 1;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
const int TASKS = 5;
const int BLOCKS = 6;
int n;
int a[121][TASKS];
long long points_cnt[TASKS];
int people_solved[TASKS];
int block_id[TASKS];
long long res = LLONG_MAX;
long long calc_need_accs() {
  long long br = LLONG_MAX;
  for (int i = 0; i < TASKS; i++) {
    long long k = block_id[i];
    if (k != 5 && a[0][i] == -1) {
      long long t = (1LL << (k + 1));
      br = min(br, t * (people_solved[i]) - n);
    }
  }
  for (long long b = 0; b < br; b++) {
    bool good = true;
    for (int i = 0; i < TASKS && good; i++) {
      long long k = block_id[i];
      if (k == 5) {
        if (b < 32LL * people_solved[i] - n) {
          good = false;
        }
      } else {
        long long t = (1LL << (k + 1));
        long long c = max(0LL, (b + n + 1 + t - 1) / t - people_solved[i]);
        if (t * (people_solved[i] + c) > 2LL * (b + n) || c > b) {
          good = false;
        }
      }
    }
    if (good) {
      return b;
    }
  }
  return LLONG_MAX;
}
long long calc_score(int my_id) {
  long long score = 0;
  for (int i = 0; i < TASKS; ++i) {
    if (a[my_id][i] == -1) continue;
    score +=
        points_cnt[block_id[i]] - points_cnt[block_id[i]] / 250 * a[my_id][i];
  }
  return score;
}
void check() {
  int my_score = calc_score(0);
  int his_score = calc_score(1);
  if (my_score <= his_score) {
    return;
  }
  long long need_accs = calc_need_accs();
  res = min(res, need_accs);
}
void go(int cur_task) {
  if (cur_task == TASKS) {
    check();
  } else {
    for (int i = 0; i < BLOCKS; ++i) {
      block_id[cur_task] = i;
      go(cur_task + 1);
    }
  }
}
int main() {
  for (int i = 0; i < BLOCKS; ++i) {
    points_cnt[i] = 500 * (i + 1);
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < TASKS; ++j) {
      scanf("%d", &a[i][j]);
      if (a[i][j] != -1) {
        people_solved[j]++;
      }
    }
  }
  go(0);
  if (res == LLONG_MAX) {
    cout << -1;
  } else {
    cout << res;
  }
  return 0;
}
