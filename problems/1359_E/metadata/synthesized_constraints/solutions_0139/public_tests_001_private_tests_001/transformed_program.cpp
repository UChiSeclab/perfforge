#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ' ' << p.second << ')';
}

template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

const bool MULTIPLE_TEST_CASES = false;
const long long MOD = 998244353;
const long long N = 1e5 + 5;
const long long INF = 1e12;

struct Arithmetic {
  long long MODULO;
  vector<long long> fact;
  Arithmetic(long long m = 1e9 + 7) { MODULO = m; }
  long long powMod(long long a, long long p) {
    if (p == 0) {
      return 1;
    } else if (p % 2 == 0) {
      long long val = powMod(a, p / 2);
      return (val * val) % MODULO;
    } else {
      long long val = powMod(a, (p - 1) / 2);
      return ((a % MODULO) * ((val * val) % MODULO)) % MODULO;
    }
  }
  bool _expandFactorial(long long n) {
    long long curSize = fact.size();
    if (curSize >= n + 1) {
      return false;
    }
    fact.resize(n + 1, 1);
    for (long long i = curSize; i < n + 1; i++) {
      if (i > 0) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MODULO;
      }
    }
    return true;
  }
  long long ncr(long long n, long long r) {
    if (n < r) {
      return 0;
    }
    _expandFactorial(n + 1);
    long long ans = fact[n] % MODULO;
    ans *= powMod(fact[n - r], MODULO - 2);
    ans %= MODULO;
    ans *= powMod(fact[r], MODULO - 2);
    ans %= MODULO;
    return ans;
  }
  long long add(long long a, long long b) { return (a + b) % MODULO; }
  long long subtract(long long a, long long b) {
    long long ans = (a - b) % MODULO;
    if (ans < 0) {
      ans += MODULO;
    }
    return ans;
  }
  long long multiply(long long a, long long b) { return (a * b) % MODULO; }
  long long divide(long long a, long long b) {
    long long bInv = powMod(b, MODULO - 2);
    return (a * bInv) % MODULO;
  }
};

Arithmetic arithmetic(MOD);

void check_iteration_count(long long n, long long k) {
    if (n > 100000 && k < 50) {
        cerr << "Warning: High iteration count in loops due to large n and small k." << endl;
        abort();
    }
}

void check_expensive_function_calls(long long n, long long k) {
    if (n > 100000 && k < 50) {
        cerr << "Warning: Frequent calls to expensive functions due to large n and small k." << endl;
        abort();
    }
}

void check_recursive_function_complexity(long long n) {
    if (n > 100000) {
        cerr << "Warning: High complexity in recursive function due to large n." << endl;
        abort();
    }
}

void solve() {
  long long n, k;
  cin >> n >> k;
  
  // Insert invariant checks before entering main computation loop
  check_iteration_count(n, k);
  check_expensive_function_calls(n, k);
  check_recursive_function_complexity(n);

  if (n < k) {
    cout << "0\n";
    return;
  }
  
  long long ans = 0;
  for (long long mn = 1; mn <= n; mn++) {
    long long numDivisors = n / mn;
    ans += arithmetic.ncr(numDivisors - 1, k - 1);
    ans %= MOD;
  }
  cout << ans << "\n";
  return;
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  if (MULTIPLE_TEST_CASES) cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}