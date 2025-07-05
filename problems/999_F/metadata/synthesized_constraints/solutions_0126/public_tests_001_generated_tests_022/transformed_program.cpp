#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<V<T>>;
template <typename T>
istream& operator>>(istream& cin, V<T>& arr) {
  for (T& val : arr) {
    cin >> val;
  }
  return cin;
}
template <typename T>
ostream& operator<<(ostream& cout, V<T>& arr) {
  for (T& val : arr) {
    cout << val << ' ';
  }
  return cout;
}

void check_matrix_size_invariant(long long n, long long k) {
    if (n > 400 && k >= 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to large matrix operations!" << endl;
        abort();
    }
}

void check_repeated_card_matching(long long uniqueFavoriteNumbers, long long n) {
    if (uniqueFavoriteNumbers < n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to repeated card distribution and matching!" << endl;
        abort();
    }
}

void check_joy_level_invariant(const vector<long long>& h) {
    if (h.back() > 90000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large joy level calculations!" << endl;
        abort();
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> c(n * k);
  cin >> c;
  vector<long long> f(n);
  cin >> f;
  vector<long long> h(k);
  cin >> h;

  // Check for potential performance bottlenecks
  check_matrix_size_invariant(n, k);
  check_joy_level_invariant(h);
  
  // Count unique favorite numbers
  set<long long> uniqueFavorites(f.begin(), f.end());
  check_repeated_card_matching(uniqueFavorites.size(), n);
  
  sort(c.begin(), c.end());
  sort(f.begin(), f.end());
  vector<vector<long long>> ma(5001, vector<long long>(501));
  for (long long i = 1; i < 5001; i++) {
    for (long long j = 1; j < 501LL; j++) {
      if (j * k <= i) {
        ma[i][j] = h[k - 1] * j;
      } else {
        ma[i][j] = ma[i][j - 1];
        for (long long q = 1; q <= k && i - q >= 0; q++) {
          ma[i][j] = max(ma[i][j], h[q - 1] + ma[i - q][j - 1]);
        }
      }
    }
  }
  long long i = 0;
  long long j = 0;
  long long ans = 0;
  while (i < n) {
    long long cntPeople = 0;
    while (i + cntPeople < n && f[i + cntPeople] == f[i]) {
      cntPeople++;
    }
    while (j < n * k && c[j] < f[i]) {
      j++;
    }
    if (j < n * k && c[j] == f[i]) {
      long long cntCards = 0;
      while (j + cntCards < n * k && c[j + cntCards] == c[j]) {
        cntCards++;
      }
      ans += ma[cntCards][cntPeople];
    }
    i += cntPeople;
  }
  cout << ans;
  return 0;
}