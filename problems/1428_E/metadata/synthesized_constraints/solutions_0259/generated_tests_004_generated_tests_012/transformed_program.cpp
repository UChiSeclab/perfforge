#include <bits/stdc++.h>
using namespace std;

void mycode();
const long long int infLL = (1LL << 62);
const long long int mod = 998244353;

long long int ceil(long long int a, long long int b) { return (a + b - 1) / b; }
long long int min(long long int a, long long int b) {
  if (a > b)
    return b;
  else
    return a;
}

bool bit_check(long long int a, int i) {
  if ((a & (1LL << i))) return 1;
  return 0;
}

long long int bit_toggle(long long int a, int i) { return (a ^ (1LL << i)); }
long long int bit_sum(long long int a, int i) { return a + (1LL << i); }
long long int bit_sub(long long int a, int i) { return a - (1LL << i); }

long long int mod_power(long long int x, long long int y) {
  long long int p = mod;
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

long long int power_of(long long int a, int b) {
  if (a == 0) return -1;
  return 1 + power_of(a / b, b);
}

long long power(long long int a, long long int b) {
  if (a == 1) return 1;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

// Checker Functions
void check_rabbits_carrots_ratio(long long n, long long k) {
    if (k > 10 * n) { // Arbitrary threshold to indicate significant disparity
        cerr << "Warning: Performance bottleneck condition triggered! Too many rabbits for the number of carrots." << endl;
        abort();
    }
}

void check_priority_queue_operations(long long numAdjustments) {
    if (numAdjustments > 10000) { // Threshold indicating excessive operations
        cerr << "Warning: Performance bottleneck condition triggered! Excessive priority queue operations." << endl;
        abort();
    }
}

void check_function_f_usage(long long functionCalls) {
    if (functionCalls > 100000) { // Threshold for excessive function calls
        cerr << "Warning: Performance bottleneck condition triggered! Excessive calls to function f." << endl;
        abort();
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  mycode();
  return 0;
}

long long int f(long long int v, long long int a) {
  if (v % a == 0)
    return (v / a) * v;
  else
    return (v % a) * ceil(v, a) * ceil(v, a) + (a - v % a) * (v / a) * (v / a);
}

bool cmp2(pair<long long int, long long int> a,
          pair<long long int, long long int> b) {
  if (a.first == b.first && a.second == b.second)
    return 0;
  else {
    long long int p1 = f(a.second, a.first), p2 = f(b.second, b.first);
    for (int i = 1; i < 5; i++)
      return (p1 - f(a.second, a.first + i)) < (p2 - f(b.second, b.first + i));
    return 0;
  }
}

void mycode() {
  long long int n, k, x;
  cin >> n >> k;

  // Check initial rabbits and carrots ratio
  check_rabbits_carrots_ratio(n, k);

  auto cmp = [](pair<long long int, long long int> left,
                pair<long long int, long long int> right) {
    return cmp2(left, right);
  };

  priority_queue<pair<long long int, long long int>,
                 vector<pair<long long int, long long int> >, decltype(cmp)>
      q(cmp);
  for (int i = 0; i < n; i++) {
    cin >> x;
    q.push({1, x});
  }

  unsigned long long int ans = 0, aa, bb, cc, a, b;
  long long numAdjustments = 0; // Counter for pq operations
  long long functionCalls = 0; // Counter for function f calls

  while (k != n) {
    n++;
    bb = q.top().first;
    cc = q.top().second;
    q.pop();
    q.push({bb + 1, cc});
    numAdjustments++;

    // Check priority queue operations
    check_priority_queue_operations(numAdjustments);
  }

  while (!q.empty()) {
    bb = q.top().first;
    cc = q.top().second;
    ans += f(cc, bb);
    functionCalls++;
    q.pop();
  }

  // Check function f usage
  check_function_f_usage(functionCalls);

  cout << ans << '\n';
}