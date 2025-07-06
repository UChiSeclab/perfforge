#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;

// Checker function for large range size
void check_range_invariant(int start, int end) {
    if ((end - start) > 5000) { // Example threshold
        cerr << "Warning: range_invariant triggered - large range for bids" << endl;
        abort();
    }
}

// Checker function for overlapping bid ranges
void check_overlap_invariant(const vector<pair<int, int>>& ranges) {
    bool overlap_detected = false;
    int n = ranges.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!(ranges[i].second < ranges[j].first || ranges[j].second < ranges[i].first)) {
                overlap_detected = true;
                break;
            }
        }
        if (overlap_detected) break;
    }
    if (overlap_detected) {
        cerr << "Warning: overlap_invariant triggered - overlapping bid ranges" << endl;
        abort();
    }
}

int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
long long fun(long long a, long long b, long long c) {
  a %= c;
  b %= c;
  long long s = 0;
  while (b) {
    if (b & 1) {
      s = s + a;
      if (s >= c) s = s - c;
    }
    a = a << 1;
    if (a >= c) a = a - c;
    b = b >> 1;
  }
  return s;
}
long long pow1(long long x, long long n, long long m) {
  if (n == 0) return 1;
  if (n == 1) return x % m;
  if (n % 2 == 0)
    return pow1(fun(x, x, m), n / 2, m) % m;
  else
    return fun(pow1(fun(x, x, m), n / 2, m), x, m);
}
bool Miller_Rabin(long long n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (!(n & 1)) return false;
  long long k = 0, i, j, m = n - 1, a;
  while (!(m & 1)) m >>= 1, k++;
  for (i = 0; i < 10; i++) {
    if (pri[i] >= n) return true;
    a = pow1(pri[i], m, n);
    if (a == 1) continue;
    for (j = 0; j < k; j++) {
      if (a == n - 1) break;
      a = fun(a, a, n);
    }
    if (j == k) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  if (a % 2 == 0 && b % 2 == 0) return gcd(a >> 1, b >> 1) << 1;
  if (a % 2 == 0) return gcd(a >> 1, b);
  if (b % 2 == 0) return gcd(a, b >> 1);
  return gcd((a + b) >> 1, (a - b) >> 1);
}
long long pollard_rho(long long c, long long n) {
  long long i, x, y, k, d;
  i = 1;
  x = y = rand() % n;
  k = 2;
  do {
    i++;
    d = gcd(n + y - x, n);
    if (d > 1 && d < n) return d;
    if (i == k) y = x, k <<= 1;
    x = (fun(x, x, n) + n - c) % n;
  } while (y != x);
  return n;
}
long long rho(long long n) {
  if (Miller_Rabin(n)) return n;
  long long t = n;
  while (t >= n) t = pollard_rho(rand() % (n - 1) + 1, n);
  long long a = rho(t);
  long long b = rho(n / t);
  return a < b ? a : b;
}
int n;
int s[10], t[10];
int main() {
  while (scanf("%d", &n) != EOF) {
    vector<pair<int, int>> ranges;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &s[i], &t[i]);
      check_range_invariant(s[i], t[i]); // Check for large range
      ranges.emplace_back(s[i], t[i]);
    }
    check_overlap_invariant(ranges); // Check for overlapping ranges

    double ans = 0;
    for (int i = 0; i < n; i++) {
      bool leap = true;
      for (int j = 0; j < n; j++)
        if (i != j && t[i] < s[j]) {
          leap = false;
          break;
        }
      if (!leap) continue;
      for (int k = 0; k < n; k++) {
        if (k == i) continue;
        leap = true;
        for (int j = 0; j < n; j++)
          if (j != i && j != k && t[k] < s[j]) {
            leap = false;
            break;
          }
        if (!leap) continue;
        for (int l = s[k]; l <= t[k]; l++) {
          double tmp = 1.0;
          for (int a = 0; a < n; a++) {
            if (a != i && a != k) {
              if (l >= s[a]) {
                if (l <= t[a]) {
                  if (a > k)
                    tmp *= (double)(l - s[a] + 1) / (t[a] - s[a] + 1);
                  else
                    tmp *= (double)(l - s[a]) / (t[a] - s[a] + 1);
                } else
                  ;
              } else
                tmp = 0;
            }
          }
          double bi = 0;
          if (l < s[i])
            bi = 1.0;
          else if (l > t[i])
            bi = 0.0;
          else {
            if (i < k)
              bi = (double)(t[i] - l + 1) / (t[i] - s[i] + 1);
            else
              bi = (double)(t[i] - l) / (t[i] - s[i] + 1);
          }
          ans += (double)l / (t[k] - s[k] + 1) * bi * tmp;
        }
      }
    }
    printf("%.15lf\n", ans);
  }
  return 0;
}