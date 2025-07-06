#include <bits/stdc++.h>
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
long long mod = (1000000007LL);

inline long long Mod(long long a, long long b) { return (a % b); }
inline long long poww(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

long long gcd(long long a, long long b) {
  while (b) {
    a %= b, swap(a, b);
  }
  return a;
}

void read(vector<long long> &w, long long n) {
  w.resize(n);
  for (long long i = 0; i < n; i++) cin >> w[i];
}

void print(vector<long long> &w) {
  for (long long i = 0; i < (long long)(w).size(); i++) {
    if (i == (long long)(w).size() - 1)
      cout << w[i] << "\n";
    else
      cout << w[i] << " ";
  }
}

long long prodmod(vector<long long> w);
long long summod(vector<long long> w);
long long n, m, q, k, v[300050], ans;

// Function to calculate the cost of splitting carrots
long long cost(long long i, long long j) {
  if (v[i] % j == 0) return (v[i] / j) * (v[i] / j) * j;
  long long len1 = v[i] / j, qtd1 = j - v[i] % j;
  long long len2 = (v[i] / j + 1), qtd2 = v[i] % j;
  return len1 * len1 * qtd1 + len2 * len2 * qtd2;
}

// Checkers for performance bottlenecks
void check_cost_calculations_invariant(long long n, long long k) {
    if (k > 10 * n) { // Arbitrary threshold based on analysis
        cerr << "Warning: High repetition of cost calculations due to large k-n difference!" << endl;
        abort();
    }
}

void check_priority_queue_invariant(long long n, long long k) {
    if (k - n > 10000) { // Arbitrary threshold for excessive iterations
        cerr << "Warning: Frequent priority queue operations detected due to high k-n!" << endl;
        abort();
    }
}

void check_carrot_length_invariant(vector<long long>& v) {
    for (long long length : v) {
        if (length > 500000) { // Arbitrary large length threshold
            cerr << "Warning: Large carrot length detected, which may lead to expensive splits!" << endl;
            abort();
        }
    }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> v[i];

  // Insert checkers after reading inputs
  check_cost_calculations_invariant(n, k);
  check_priority_queue_invariant(n, k);
  check_carrot_length_invariant(vector<long long>(v + 1, v + n + 1));

  priority_queue<vector<long long>, vector<vector<long long>>,
                 greater<vector<long long>>>
      pq;
  for (long long i = 1; i <= n; i++) {
    pq.push({-cost(i, 1) + cost(i, 2), 2, i});
    ans += cost(i, 1);
  }
  for (long long cnt = 0; cnt < k - n; cnt++) {
    auto t = pq.top();
    ans += t[0];
    long long j = t[1], i = t[2];
    pq.pop();
    pq.push({-cost(i, j) + cost(i, j + 1), j + 1, i});
  }
  cout << ans << "\n";
}

long long summod(vector<long long> w) {
  long long curr = 0;
  for (long long i = 0; i < (long long)(w).size(); i++) {
    curr = (curr + w[i]) % mod;
    if (curr < 0) curr += mod;
  }
  return curr;
}

long long prodmod(vector<long long> w) {
  long long curr = 1;
  for (long long i = 0; i < (long long)(w).size(); i++) {
    if (w[i] >= mod) w[i] %= mod;
    curr = (curr * w[i]) % mod;
    if (curr < 0) curr += mod;
  }
  return curr;
}