#include <bits/stdc++.h>
using namespace std;

// Function to check large number of divisors
void check_large_divisor_count(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to high number of divisors!" << endl;
        abort();
    }
}

// Function to check large value of D
void check_large_value_of_D(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large value of D!" << endl;
        abort();
    }
}

// Function to check high prime density
void check_high_prime_density(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to high prime density!" << endl;
        abort();
    }
}

template <class T, class U>
void ckmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
void ckmax(T &a, U b) {
  if (a < b) a = b;
}
const int INF = 998244353;
long long D;
int Q;
vector<long long> primes;
int fact[70], ifact[70];
int mul(int a, int b) { return (long long)a * b % INF; }
int pwr(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int32_t main() {
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(4);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for (auto i = (1); i < (69); i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[68] = pwr(fact[68], INF - 2);
  for (auto i = (68) - 1; i >= (0); i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  cin >> D >> Q;
  
  // Check for large value of D
  check_large_value_of_D(D > 1e14); // Example threshold for large D

  long long d = D;
  int divisor_count = 0;
  
  for (long long i = 2; i * i <= D; i++) {
    if (d % i) continue;
    primes.push_back(i);
    while (d % i == 0) d /= i;
    divisor_count++;
  }
  if (d > 1) primes.push_back(d);
  divisor_count++;
  
  // Check for high number of divisors
  check_large_divisor_count(divisor_count > 100); // Example threshold for divisors

  // Check for high prime density
  check_high_prime_density(primes.size() > 5); // Example threshold for prime density

  while (Q--) {
    int incr = 0, decr = 0;
    long long u, v;
    cin >> u >> v;
    long long ans = 1;
    for (long long p : primes) {
      int net = 0;
      while (u % p == 0) {
        net++;
        u /= p;
      }
      while (v % p == 0) {
        net--;
        v /= p;
      }
      ans = mul(ans, ifact[abs(net)]);
      if (net < 0)
        incr -= net;
      else
        decr += net;
    }
    ans = mul(ans, fact[incr]);
    ans = mul(ans, fact[decr]);
    cout << ans << '\n';
  }
  return 0;
}