#include <bits/stdc++.h>
int N, K;
using ll = long long;
const ll MOD = 1000000007;
const int MAXN = 250;
ll fact[MAXN + 1], invfact[MAXN + 1];
ll madd(ll a, ll b) { return ((a + b) % MOD + MOD) % MOD; }
ll mmult(ll a, ll b) { return (a * b) % MOD; }
ll modpow(ll x, ll y, ll p) {
  ll res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
ll modinv(ll x) { return modpow(x, MOD - 2, MOD); }
void calcFact() {
  fact[0] = invfact[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    fact[i] = (i * fact[i - 1]) % MOD;
    invfact[i] = modinv(fact[i]);
  }
}
ll choose(ll n, ll r) {
  return mmult(fact[n], mmult(invfact[r], invfact[n - r]));
}
ll T[259][259];

// Checker functions
void check_large_k_invariant(bool condition) {
    if (condition) {
        std::cerr << "Warning: Performance bottleneck due to large K values!" << std::endl;
        abort();
    }
}

void check_combination_invariant(bool condition) {
    if (condition) {
        std::cerr << "Warning: Performance bottleneck due to frequent combination calculations!" << std::endl;
        abort();
    }
}

void check_nested_loops_invariant(bool condition) {
    if (condition) {
        std::cerr << "Warning: Performance bottleneck due to complex nested loops!" << std::endl;
        abort();
    }
}

int main(void) {
  std::cin >> N >> K;
  
  // Check if K is large and might cause slowdowns with modpow
  check_large_k_invariant(K > 1e8); // Example threshold for K

  if (K == 1) {
    std::cout << "1\n";
    return 0;
  }
  
  calcFact();

  ll mp1[251];
  ll mp2[251];
  for (int i = 0; i <= N; i++) {
    mp1[i] = modpow(K, i, MOD);
    mp2[i] = modpow(K - 1, i, MOD);
  }

  // Check nested loops complexity before processing
  check_nested_loops_invariant(N > 200); // Example threshold for N

  T[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    T[i][0] =
        mmult(madd(modpow(K, N, MOD), -modpow(K - 1, N, MOD)), T[i - 1][0]);
  }
  for (int j = 1; j <= N; j++) {
    T[1][j] = modpow(K, N - j, MOD);
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      T[i][j] =
          mmult(T[i - 1][j], mmult(madd(mp1[N - j], -mp2[N - j]), mp2[j]));
      ll tmp = 0;
      for (int k = 1; k <= j; k++) {
        tmp =
            madd(tmp, mmult(mmult(choose(j, k), mp2[j - k]), T[i - 1][j - k]));
      }
      tmp = mmult(tmp, mp1[N - j]);
      T[i][j] = madd(T[i][j], tmp);
    }
  }

  // Check combination calculations frequency
  check_combination_invariant(T[N][N] > 1e5); // Example threshold for results size

  std::cout << T[N][N] << '\n';
}