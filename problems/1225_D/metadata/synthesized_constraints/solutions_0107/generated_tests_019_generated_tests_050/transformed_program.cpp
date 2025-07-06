#include <bits/stdc++.h>
using namespace std;
const int N = 110000, base = 19260817, mod = 1e9 + 7;
unsigned long long ans, hsa[N], hsb[N];
int n, k, a[N], prime[N], nopr;
map<int, int> fac[N];
map<unsigned long long, long long> buc;

// Function to read input
template <class T>
inline void read(T &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
  return;
}

// Quick power calculation
inline long long quickpow(long long base, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1) ret = ret * base;
    base = base * base, pw >>= 1;
  }
  return ret;
}

// Performance check functions
void check_max_element_invariant(int maxA) {
  if (maxA > 50000) {
    cerr << "Warning: Performance bottleneck condition triggered due to high maximum element!" << endl;
    abort();
  }
}

void check_exponentiation_invariant(int base, int power) {
  if (base > 10000 && power > 50) {
    cerr << "Warning: Performance bottleneck due to repeated high exponentiation!" << endl;
    abort();
  }
}

void check_prime_factorization_invariant(int nopr) {
  if (nopr > 5000) {
    cerr << "Warning: Performance bottleneck due to handling many prime factors!" << endl;
    abort();
  }
}

void check_small_n_large_values_invariant(int n, int maxA) {
  if (n < 10 && maxA > 90000) {
    cerr << "Warning: Performance bottleneck due to small n with large values!" << endl;
    abort();
  }
}

int main() {
  int maxA = 0;
  read(n), read(k);
  for (register int i = 1; i <= n; ++i) read(a[i]), maxA = max(maxA, a[i]);
  
  // Insert performance check for maximum element
  check_max_element_invariant(maxA);
  check_small_n_large_values_invariant(n, maxA);
  
  for (register int i = 2; i <= maxA; ++i) {
    if (fac[i].empty()) fac[i][i] = 1, prime[++nopr] = i;
    for (register int j = 1, k; j <= nopr && (k = i * prime[j]) <= maxA; ++j) {
      fac[k] = fac[i], ++fac[k][prime[j]];
      if (i % prime[j] == 0) break;
    }
    for (register auto j = fac[i].begin(); j != fac[i].end(); ++j) {
      if (j->second % k == 0) continue;
      int base = j->first;
      int power = j->second % k;
      hsa[i] = hsa[i] * base ^ quickpow(base, power) % base;
      hsb[i] = hsb[i] * base ^ quickpow(base, (k - power) % k) % base;
      
      // Insert performance check for exponentiation
      check_exponentiation_invariant(base, power);
    }
  }
  
  // Insert performance check for number of primes handled
  check_prime_factorization_invariant(nopr);
  
  for (register int i = 1; i <= n; ++i) ans += buc[hsb[a[i]]], ++buc[hsa[a[i]]];
  cout << ans << endl;
  return 0;
}