#include <bits/stdc++.h>
using namespace std;

namespace combo {
const long long MOD = 998244353;
vector<long long> inv = {-1, 1};
vector<long long> fact = {1, 1};
vector<long long> ifact = {1, 1};
int precalculated = 1;
void calc_factorials(int n) {
  if (n <= precalculated) {
    return;
  }
  fact.resize(n + 1);
  inv.resize(n + 1);
  ifact.resize(n + 1);
  for (int i = precalculated + 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = -MOD / i * inv[MOD % i] % MOD;
    ifact[i] = ifact[i - 1] * inv[i] % MOD;
  }
  precalculated = n;
}
long long choose(int n, int k) {
  if (n < k) {
    return 0;
  }
  calc_factorials(n);
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}
long long permute(int n, int k) {
  if (n < k) {
    return 0;
  }
  calc_factorials(n);
  return fact[n] * ifact[n - k] % MOD;
}
}  // namespace combo
using namespace combo;

// Checker function for prime factorization complexity
void check_prime_factorization_complexity(long long d) {
    int prime_count = 0;
    for (long long x = 2; x * x <= d; x++) {
        if (d % x == 0) {
            prime_count++;
            while (d % x == 0) {
                d /= x;
            }
        }
    }
    if (d > 1) prime_count++;  // d is prime
    if (prime_count > 20) {
        cerr << "Warning: Prime factorization complexity triggered - too many distinct prime factors" << endl;
        abort();
    }
}

// Checker function for factorial calculation complexity
void check_factorial_calculation_complexity(const vector<int>& diffs) {
    int sum = 0;
    for (int d : diffs) {
        sum += abs(d);
    }
    if (sum > 100) {  // Arbitrary threshold for complexity
        cerr << "Warning: Factorial calculation complexity triggered - high sum of exponent differences" << endl;
        abort();
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long d;
  cin >> d;
  
  // Check prime factorization complexity at the start
  check_prime_factorization_complexity(d);

  vector<pair<long long, int>> f;
  long long dd = d;
  for (long long x = 2; x * x <= dd; x++) {
    int e = 0;
    while (d % x == 0) {
      d /= x;
      e++;
    }
    if (e > 0) {
      f.emplace_back(x, e);
    }
  }
  if (d > 1) {
    f.emplace_back(d, 1);
  }

  int q;
  cin >> q;
  while (q--) {
    long long u, v;
    cin >> u >> v;
    vector<pair<int, int>> exps;
    vector<int> diffs;
    for (const auto &p : f) {
      int a = 0;
      while (u % p.first == 0) {
        u /= p.first;
        a++;
      }
      int b = 0;
      while (v % p.first == 0) {
        v /= p.first;
        b++;
      }
      exps.emplace_back(a, b);
      diffs.emplace_back(a - b);
    }

    // Check factorial calculation complexity based on diffs
    check_factorial_calculation_complexity(diffs);

    vector<int> pos, neg;
    for (int d : diffs) {
      if (d > 0) {
        pos.push_back(d);
      }
      if (d < 0) {
        neg.push_back(-d);
      }
    }
    long long ans = 1;
    for (int _ = 0; _ < 2; _++) {
      int sum = accumulate(pos.begin(), pos.end(), 0);
      calc_factorials(sum);
      ans *= fact[sum];
      ans %= MOD;
      for (int d : pos) {
        ans *= ifact[d];
        ans %= MOD;
      }
      swap(pos, neg);
    }
    if (ans < 0) {
      ans += MOD;
    }
    cout << ans << '\n';
  }
  return 0;
}