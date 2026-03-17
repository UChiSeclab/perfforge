#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 5LL;
const long long inf32 = INT_MAX;
const long long mod = 1e9 + 7LL;
const long long N = (1e6 + 10);
void solve(long long t);
void solve();
void ITO();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ITO();
  long long t = 1;
  for (long long i = 0; i < t; i++) solve(i + 1);
  return 0;
}
bool check(vector<long long>& arr, long long n, vector<long long>& each,
           long long k, long long i) {
  if (i == 6) {
    if (*max_element(each.begin(), each.end()) <= n)
      return 1;
    else
      return 0;
  }
  for (long long j = 0; j < k; ++j) {
    each[j] += arr[i];
    if (check(arr, n, each, k, i + 1)) return 1;
    each[j] -= arr[i];
  }
  return 0;
}
void solve(long long TcNumber) {
  long long n;
  cin >> n;
  long long a, b;
  cin >> a >> b;
  vector<long long> arr({a, a, a, a, b, b});
  long long res = 1;
  while (res < 6) {
    vector<long long> each(res, 0);
    if (check(arr, n, each, res, 0)) break;
    res++;
  }
  cout << res;
  cout << "\n";
  return;
}
void solve() {}
void ITO() {}
