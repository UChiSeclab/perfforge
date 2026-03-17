#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string s;
long long ans;
bool flag;
void solve() {
  long long n, b;
  cin >> n >> b;
  long long c = 0;
  vector<long long> f;
  vector<long long> freq;
  long long B = b;
  if (b == 1) {
    cout << 0;
    return;
  }
  for (long long i = 2; i <= sqrt(b); i++) {
    int ff = 0;
    while (B % i == 0) {
      B = B / i;
      ff++;
    }
    if (ff > 0) {
      f.push_back(i);
      freq.push_back(ff);
    }
  }
  if (B > 1) {
    f.push_back(B);
    freq.push_back(1);
  }
  long long ans = 1700000000000000000;
  for (int i = 0; i < f.size(); i++) {
    long long N = n;
    c = 0;
    while (N > 0) {
      N = N / f[i];
      c += N;
    }
    c = c / freq[i];
    ans = min(ans, c);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
