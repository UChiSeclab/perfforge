#include <bits/stdc++.h>
const double PI = acos(-1);
const double EPS = 1e-6;
const long long MOD = 1000000007;
const long long INF = 0x3F3F3F3F;

// Checker functions for performance invariants
void check_sort_invariant(int sortCount, int n) {
    if (sortCount > n / 2) {
        cerr << "Warning: sort_invariant triggered - frequent sorting operations" << endl;
        abort();
    }
}

void check_loop_invariant(int loopCount, int n) {
    if (loopCount > n * n) {
        cerr << "Warning: loop_invariant triggered - excessive loop iterations" << endl;
        abort();
    }
}

void check_zero_durability_invariant(int zeroDurabilityCount, int n) {
    if (zeroDurabilityCount > n * 2) {
        cerr << "Warning: zero_durability_invariant triggered - frequent zero durability checks" << endl;
        abort();
    }
}

template <typename T>
inline T Abs(T x) {
  return x < 0 ? x * -1 : x;
}
template <typename T>
inline T Max(T x, T y, T z) {
  return std::max(std::max(x, y), z);
}
template <typename T>
inline T Min(T x, T y, T z) {
  return std::min(std::min(x, y), z);
}
template <typename T>
inline T Ckmax(T &x, T y) {
  return x = std::max(x, y);
}
template <typename T>
inline T Ckmin(T &x, T y) {
  return x = std::min(x, y);
}
template <typename T>
inline T Sqr(T x) {
  return x * x;
}
template <typename T>
inline T Pow(T x, T y) {
  T r = 1;
  while (y > 0) {
    if (y % 2 > 0) (r *= x) %= MOD;
    (x *= x) %= MOD;
    y /= 2;
  }
  return r % MOD;
}
template <typename T>
T Pow(T x, T y, T z) {
  T r = 1;
  while (y > 0) {
    if (y % 2 > 0) (r *= x) %= z;
    (x *= x) %= z;
    y /= 2;
  }
  return r % z;
}
template <typename T>
inline T gcd(T x, T y) {
  return y > 0 ? gcd(y, x % y) : x;
}
template <typename T>
inline T lcm(T x, T y) {
  return x / gcd(x, y) * y;
}
inline void cinspu(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
}
inline long long read(void) {
  char x;
  while (x = getchar(), x != '-' && !isdigit(x))
    ;
  char flg = x == '-';
  long long num = (flg ? getchar() : x) - '0';
  while (isdigit(x = getchar())) (num *= 10) += x - '0';
  return flg ? -num : num;
}
const int N = 5000 + 10;
int a[N];
int main() {
  cinspu();
  int n, x, y;
  std::cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  if (x > y) {
    std::cout << n << std::endl;
    return 0;
  }
  
  int sortCount = 0;
  int loopCount = 0;
  int zeroDurabilityCount = 0;
  
  for (int ans = 0;;) {
    std::sort(a + 1, a + n + 1);
    sortCount++;
    check_sort_invariant(sortCount, n); // Check for frequent sorting
    
    int p = 1;
    for (; p <= n && a[p] <= x; ++p) {
      loopCount++;
      check_loop_invariant(loopCount, n); // Check for excessive loop iterations
    }
    --p;
    if (!a[p] || a[p] > x) {
      std::cout << ans << std::endl;
      return 0;
    }
    ++ans;
    a[p] = 0;
    
    for (p = 1; p <= n && !a[p]; ++p) {
      zeroDurabilityCount++;
      check_zero_durability_invariant(zeroDurabilityCount, n); // Check for frequent zero durability checks
    }
    
    if (p <= n)
      a[p] += y;
    else {
      std::cout << ans << std::endl;
      return 0;
    }
  }
  return 0;
}