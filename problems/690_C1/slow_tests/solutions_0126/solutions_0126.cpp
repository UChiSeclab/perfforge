#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long binpow(long long base, long long exp) {
  long long mod = 1000000007LL;
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
long long mod(long long x) {
  return ((x % 1000000007LL + 1000000007LL) % 1000000007LL);
}
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
const long long N = (long long)1e6;
void sieve(long long N) {
  bool prime[N + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= N; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= N; i += p) prime[i] = false;
    }
  }
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007LL;
  }
  return res;
}
long long C(long long n, long long k) {
  return fact(n) * 1ll * binpow(fact(k), 1000000007LL - 2) % 1000000007LL *
         1ll * binpow(fact(n - k), 1000000007LL - 2) % 1000000007LL;
}
long long n, m;
unordered_map<long long, vector<long long>> adj;
vector<long long> vis;
void dfs(long long src) {
  vis[src] = 1;
  for (auto x : adj[src]) {
    if (vis[x] == -1) {
      dfs(x);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  vis.resize(n + 1, -1);
  for (long long i = 1; i <= m; i++) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  long long cn = 0;
  for (long long i = 1; i <= n; i++) {
    if (vis[i] == -1) {
      dfs(i);
      cn++;
    }
  }
  if (m == n - 1 && cn == 1) {
    cout << "yes";
  } else {
    cout << "no";
  }
  return 0;
}
